#pragma once
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <string.h>

#define MAX_PROCESS 10
int process_number = 0;                       //下一个可用的进程编号

typedef struct pcb {
	struct pcb *next;                             //下一个进程控制块指针
	char process_name[20];                      //进程名
	int process_number;                          //进程编号
	int process_start_moment;                    //进程启动时刻
	int process_need_time;                       //要求运行时间
	int process_time_slice;                       //时间片
	int process_priority;                          //优先数
}PCB;                                       //自定义数据类型：进程控制块
PCB pcb_table[MAX_PROCESS];              //进程控制块表

PCB *pcb_run = NULL;                        //进程运行队列头指针
PCB *pcb_free = NULL;                       //进程空闲队列头指针
PCB *pcb_ready = NULL;                      //进程就绪队列头指针
PCB *pcb_ready_rear = NULL;                 //进程就绪队列尾指针
PCB *pcb_blocked = NULL;                    //阻塞队列头指针
PCB *pcb_blocked_rear = NULL;               //阻塞队列尾指针

void init_pcb_table();                          //初始化进程控制块表
void print_space(int num);                     //显示若干个空格
void display_process_queue(PCB *queue);      //显示进程队列
PCB *create_process();          //创建进程函数,成功时返回新创建进程的PCB,失败时返回NULL。
void block_process_by_name();                //阻塞指定名称的进程。
void wakeup_process();                       //唤醒进程
void FCFS();                                 //先来先服务进程调度算法
void RR();                                   //时间片轮转进程调度算法
void HPF();                                  //优先数进程调度算法
void MFBQ();                                //多级反馈队列进程调度算法

