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


//��ʼ�����̿��ƿ��������Ϊ���ַ���,��������ʱ��Ϊ0,Ҫ������ʱ��Ϊ0,ʱ��ƬΪ0,������Ϊ0.
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

//��ʾ���̶���
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

//��ʾ���ɸ��ո�
void print_space(int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf(" ");
	}
}

//�����ȷ�����̵����㷨
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
//ɾ������
void delete_process_by_name()
{
	char name[20];
	int i;
	pcb *p, *q;
	if (pcb_ready != NULL || pcb_free != NULL)
	{
		printf("              ready  queue\n");
		display_process_queue(pcb_ready);
	}
	if (pcb_blocked != NULL)

	{
		printf("              blocked  queue\n");
		display_process_queue(pcb_blocked);
	}
	if (pcb_run != NULL)
	{
		printf("              running  queue\n");
		display_process_queue(pcb_run);
	}
	printf("����������ɾ���Ľ��̵Ľ�����:\n");
	scanf("%s", name);
	for (i = 1, p = pcb_ready, q = pcb_ready; p != NULL; p = p->next, i = 0)
	{
		if (i == 1)
		{
			if (strcmp(name, (*p).process_name) == 0)
			{
				pcb_ready = pcb_ready->next;
				p->next = NULL;
			}
		}
		if (i == 0)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				q->next = p->next;
				p->next = NULL;
			}
			else
				q = p;
		}
	}
	for (i = 1, p = pcb_free, q = pcb_free; p != NULL; p = p->next, i = 0)
	{
		if (i == 1)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				pcb_free = pcb_free->next;
				p->next = NULL;
			}
		}
		if (i == 0)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				q->next = p->next;
				p->next = NULL;
			}
			else
				q = p;
		}
	}
	for (i = 1, p = pcb_blocked, q = pcb_blocked; p != NULL; p = p->next, i = 0)
	{
		if (i == 1)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				pcb_blocked = pcb_blocked->next;
				p->next = NULL;
			}
		}
		if (i == 0)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				q->next = p->next;
				p->next = NULL;
			}
			else
				q = p;
		}
	}
	for (i = 1, p = pcb_run, q = pcb_run; p != NULL; p = p->next, i = 0)
	{
		if (i == 1)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				pcb_run = pcb_run->next;
				p->next = NULL;
			}
		}
		if (i == 0)
		{
			if (strcmp((*p).process_name, name) == 0)
			{
				q->next = p->next;
				p->next = NULL;
			}
			else
				q = p;
		}
	}
}


//ʱ��Ƭ��ת���̵����㷨
void RR()
{
	int i, j = 1;
	pcb *p, *q;
	if (pcb_ready == NULL && pcb_run == NULL)
	{
		printf("ready and run queue is empty,no process to run.\n");
	}
	else
	{
		if (pcb_ready != NULL)
		{
			p = pcb_ready;
			pcb_run = pcb_ready;
			q = pcb_ready;
		}
		if (pcb_run != NULL)
		{
			p = pcb_run;
			q = pcb_run;
		}
		for (; pcb_run != NULL;)
		{
			for (i = 0; i < ((*pcb_run).process_time_slice) && ((*pcb_run).process_need_time) != 0; i++)
			{
				(*pcb_run).process_need_time = (*pcb_run).process_need_time - 1;
			}
			if ((*pcb_run).process_need_time == 0)
			{
				if (j == 1)
				{
					p = pcb_run->next;
					pcb_run = pcb_run->next;
					q = p;
				}
				else
				{
					p->next = pcb_run->next;
					pcb_run = pcb_run->next;
				}
			}
			else
			{
				p = pcb_run;
				pcb_run = pcb_run->next;
			}
			j = 0;
		}
		pcb_run = q;
		pcb_ready = NULL;
	}
}


//���������̵����㷨
void HPF()
{
	int i = -1, j = 1, t = 1;
	pcb *p, *q, *n;
	if (pcb_ready == NULL)
	{
		printf("ready queue is empty,no process to run.\n");
	}
	else
	{
		pcb_run = pcb_ready;
		p = pcb_ready;
		q = pcb_ready;
		n = pcb_ready;
		for (i = (*p).process_priority; p != NULL; p = p->next)
		{
			t--;
			if ((*p).process_priority > i)
			{
				i = (*p).process_priority;
				pcb_run = p;
				j = 0;
				n = q;
			}
			else
			{
				if (t < 0) q = p;
			}
		}
		if (j == 0)
		{
			n->next = pcb_run->next;
			pcb_run->next = NULL;
		}
		else
		{
			pcb_ready = pcb_ready->next;
			pcb_run->next = NULL;
		}
	}
}


//�༶�������н��̵����㷨
void MFBQ()
{
	if (pcb_ready == NULL)
	{
		printf("ready queue is empty,no process to run.\n");
	}
	else
	{
		int i, j = 1;
		pcb *p, *q;
		p = pcb_ready;
		pcb_run = pcb_ready;
		q = pcb_ready;
		if (pcb_run != NULL)
		{
			p = pcb_run;
			q = pcb_run;
		}
		for (; pcb_run != NULL;)
		{
			for (i = 0; i < ((*pcb_run).process_time_slice) && ((*pcb_run).process_need_time) != 0; i++)
			{
				(*pcb_run).process_need_time = (*pcb_run).process_need_time - 1;
			}
			(*pcb_run).process_time_slice++;
			(*pcb_run).process_priority++;
			if ((*pcb_run).process_need_time == 0)
			{
				if (j == 1)
				{
					p = pcb_run->next;
					pcb_run = pcb_run->next;
					q = p;
				}
				else
				{
					p->next = pcb_run->next;
					pcb_run = pcb_run->next;
				}
			}
			else
			{
				p = pcb_run;
				pcb_run = pcb_run->next;
			}
			j = 0;
		}
		pcb_ready = q;
		pcb_run = NULL;
	}
}


//�������̺���
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
		p->process_number = (process_number + 1) % 100;         //���ɽ��̱��
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

//�������̺���
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
	while (p != NULL) {            //�ھ��������в���ָ�����ƵĽ���
		if (!strcmp(p->process_name, process_name))
			break;
		previous_p = p;
		p = p->next;
	}
	if (p == NULL)                //û���ҵ�ָ�����ƵĽ���
	{
		printf("no such a process in ready queue:%s\nyou typed the wrong name\n", process_name);
		return;
	}
	else                       //�ҵ���ָ�����ƵĽ���
	{
		if (p == pcb_ready_rear)           //�ҵ��Ľ����Ǿ������������һ������
		{
			pcb_ready_rear = previous_p;
		}
		previous_p->next = p->next;         //��ָ�����ƵĽ��̴Ӿ���������ɾ��
		if (pcb_blocked == NULL)          //��������Ϊ��
		{
			pcb_blocked = pcb_blocked_rear = p;
			p->next = NULL;
		}
		else                          //�������в���
		{
			pcb_blocked_rear->next = p;
			pcb_blocked_rear = pcb_blocked_rear->next;
			p->next = NULL;
		}
	}

}

//���ѽ��̺���
void wakeup_process()
{
	PCB *p = pcb_blocked;
	if (pcb_blocked == NULL)                         //��������Ϊ�գ�û�н�����Ҫ������
	{
		printf("blocked queue is empty,no process needs to be wakeuped.\n");
	}
	else {                                           //�������в�Ϊ�գ����׽�����Ҫ������

		if (pcb_blocked == pcb_blocked_rear)         //����������ֻ��һ�����̣����Ѻ����Ϊ��
			pcb_blocked = pcb_blocked_rear = NULL;
		else                                      //�����������ж������
			pcb_blocked = pcb_blocked->next;  //ɾ�����׽���


		if (pcb_ready == NULL)                          //��������Ϊ�ղ����ھ���������
		{
			pcb_ready = pcb_ready_rear = p;
			p->next = NULL;
		}
		else                                            //�������в�Ϊ��������������β
		{
			pcb_ready_rear->next = p;
			pcb_ready_rear = pcb_ready_rear->next;
			p->next = NULL;
		}
	}
}//wakeup
