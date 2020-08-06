#include "process_schedule.h"
int main(int argc, char *argv[]) {
	char select;
	init_pcb_table();
	while (1) {
		printf("|----------MAIN    MENU-------------|\n");
		printf("|  1:first come first served        |\n");
		printf("|  2:round robin                    |\n");
		printf("|  3:highest priority first         |\n");
		printf("|  4:multi_level feedback queue     |\n");
		printf("|  5:display ready process queue    |\n");
		printf("|  6:display blocked process queue  |\n");
		printf("|  7:display running queue          |\n");
		printf("|  a:create a process               |\n");
		printf("|  b:delete a process               |\n");
		printf("|  c:block  a process               |\n");
		printf("|  d:wakeup  a process              |\n");
		printf("|  8:exit                           |\n");
		printf("|-----------------------------------|\n");
		printf("select a function(1~8,a~d):");
		do {
			select = (char)getch();
		} while (!((49 <= select && select <= 56) || (97 <= select && select <= 100)));
		system("cls");
		switch (select) {
		case '1':
			FCFS();
			break;
		case '2':
			RR();
			break;
		case '3':
			HPF();
			break;
		case '4':
			MFBQ();
			break;
		case '5':
			printf("              ready  queue\n");
			display_process_queue(pcb_ready);
			break;
		case '6':
			printf("              blocked  queue\n");
			display_process_queue(pcb_blocked);
			break;
		case '7':
			printf("              running  queue\n");
			display_process_queue(pcb_run);
			break;
		case 'a':
			create_process();
			break;
		case 'b':
			break;
		case 'c':
			block_process_by_name();
			break;
		case 'd':
			wakeup_process();
			break;
		case '8':
			return 0;
		}
		printf("\nPress any key to return to main menu.");
		getch();
		system("cls");
	}
	return 0;
}


//初始化进程控制块表：进程名为空字符串,进程启动时刻为0,要求运行时间为0,时间片为0,优先数为0.
void init_pcb_table()
{
	int i = 0;
	pcb_free = &pcb_table[0];
	pcb_table[MAX_PROCESS - 1].next = NULL;
	pcb_table[MAX_PROCESS - 1].process_number = 0;
	pcb_table[MAX_PROCESS - 1].process_start_moment = 0;
	pcb_table[MAX_PROCESS - 1].process_need_time = 0;
	pcb_table[MAX_PROCESS - 1].process_time_slice = 0;
	pcb_table[MAX_PROCESS - 1].process_priority = 0;
	strcpy(pcb_table[MAX_PROCESS - 1].process_name, "");
	for (i = 0; i < MAX_PROCESS - 1; i++) {
		pcb_table[i].next = &pcb_table[i + 1];
		pcb_table[i].process_number = 0;
		pcb_table[i].process_start_moment = 0;
		pcb_table[i].process_need_time = 0;
		pcb_table[i].process_time_slice = 0;
		pcb_table[i].process_priority = 0;
		strcpy(pcb_table[i].process_name, "");
	}

}

//显示进程队列
void display_process_queue(PCB *queue)
{
	PCB *p = queue;
	char buffer[10];
	printf("|--------------|---------|-------|------|-------|----------|\n");
	printf("| name         | number  | start | need | slice | priority |\n");
	printf("|--------------|---------|-------|------|-------|----------|\n");
	while (p != NULL) {
		printf("| ");
		printf("%s", p->process_name);
		print_space(13 - strlen(p->process_name));
		printf("| ");
		printf("%d", p->process_number);
		itoa(p->process_number, buffer, 10);
		print_space(8 - strlen(buffer));
		printf("| ");
		printf("%d", p->process_start_moment);
		itoa(p->process_start_moment, buffer, 10);
		print_space(6 - strlen(buffer));
		printf("| ");
		printf("%d", p->process_need_time);
		itoa(p->process_need_time, buffer, 10);
		print_space(5 - strlen(buffer));
		printf("| ");
		printf("%d", p->process_time_slice);
		itoa(p->process_time_slice, buffer, 10);
		print_space(6 - strlen(buffer));
		printf("| ");
		printf("%d", p->process_priority);
		itoa(p->process_priority, buffer, 10);
		print_space(9 - strlen(buffer));
		printf("|\n");
		p = p->next;
	}
	printf("|--------------|---------|-------|------|-------|----------|\n");
}

//显示若干个空格
void print_space(int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf(" ");
	}
}

//先来先服务进程调度算法
void FCFS()
{
	if (pcb_ready == NULL)
	{
		printf("ready queue is empty,no process to run.\n");
	}
	else
	{
		pcb_run = pcb_ready;
		if (pcb_ready == pcb_ready_rear)
		{
			pcb_ready = pcb_ready_rear = NULL;
		}
		else
		{
			pcb_ready = pcb_ready->next;
		}
		pcb_run->next = NULL;
	}
}

//时间片轮转进程调度算法
void RR()
{
	if (pcb_ready == NULL)
	{
		printf("ready queue is empty,no process to run.\n");
	}
	else
	{
		pcb_run = pcb_ready;
		if (pcb_ready == pcb_ready_rear)
		{
			pcb_ready = pcb_ready_rear = NULL;
		}
		else
		{
			pcb_ready = pcb_ready->next;
		}
		pcb_run->next = NULL;
	}
}

//优先数进程调度算法
void HPF()
{
}

//多级反馈队列进程调度算法
void MFBQ()
{
}


//创建进程函数
PCB *create_process()
{
	PCB *p = pcb_free;
	if (p == NULL)
		return NULL;
	else
	{
		pcb_free = pcb_free->next;
		system("cls");
		printf("please enter the following fields:\n");
		printf("| name | start_moment | need_time | time_slice | priority |\n");
		scanf("%s%d%d%d%d",
			p->process_name,
			&(p->process_start_moment),
			&(p->process_need_time),
			&(p->process_time_slice), &(p->process_priority));
		p->process_number = (process_number + 1) % 100;         //生成进程编号
		process_number++;
		p->next = NULL;
		if (pcb_ready == NULL)
			pcb_ready = pcb_ready_rear = p;
		else
		{
			pcb_ready_rear->next = p;
			pcb_ready_rear = p;
		}
		return p;
	}
}

//阻塞进程函数
void block_process_by_name()
{
	char process_name[20];
	PCB *p = pcb_ready;
	PCB *previous_p = pcb_ready;
	if (p == NULL)
	{
		printf("ready queue is empty,no process can be blocked!\n");
		return;
	}
	display_process_queue(pcb_ready);
	printf("enter the process name you want to block:\n");
	scanf("%s", process_name);
	while (p != NULL) {            //在就绪队列中查找指定名称的进程
		if (!strcmp(p->process_name, process_name))
			break;
		previous_p = p;
		p = p->next;
	}
	if (p == NULL)                //没有找到指定名称的进程
	{
		printf("no such a process in ready queue:%s\nyou typed the wrong name\n", process_name);
		return;
	}
	else                       //找到了指定名称的进程
	{
		if (p == pcb_ready_rear)           //找到的进程是就绪队列中最后一个进程
		{
			pcb_ready_rear = previous_p;
		}
		previous_p->next = p->next;         //将指定名称的进程从就绪队列中删除
		if (pcb_blocked == NULL)          //阻塞队列为空
		{
			pcb_blocked = pcb_blocked_rear = p;
			p->next = NULL;
		}
		else                          //阻塞队列不空
		{
			pcb_blocked_rear->next = p;
			pcb_blocked_rear = pcb_blocked_rear->next;
			p->next = NULL;
		}
	}

}

//唤醒进程函数
void wakeup_process()
{
	PCB *p = pcb_blocked;
	if (pcb_blocked == NULL)                         //阻塞队列为空，没有进程需要被唤醒
	{
		printf("blocked queue is empty,no process needs to be wakeuped.\n");
	}
	else {                                           //阻塞队列不为空，队首进程需要被唤醒

		if (pcb_blocked == pcb_blocked_rear)         //阻塞队列中只有一个进程，唤醒后队列为空
			pcb_blocked = pcb_blocked_rear = NULL;
		else                                      //阻塞队列中有多个进程
			pcb_blocked = pcb_blocked->next;  //删除队首进程


		if (pcb_ready == NULL)                          //就绪队列为空插入在就绪队列首
		{
			pcb_ready = pcb_ready_rear = p;
			p->next = NULL;
		}
		else                                            //就绪队列不为空则插入就绪队列尾
		{
			pcb_ready_rear->next = p;
			pcb_ready_rear = pcb_ready_rear->next;
			p->next = NULL;
		}
	}
}//wakeup
