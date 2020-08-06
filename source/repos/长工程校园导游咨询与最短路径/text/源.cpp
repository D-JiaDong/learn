#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 11   //最大顶点个数
#define Road 100   //最多路径
int Num = 10;     //目前顶点个数
using namespace std;
typedef struct Elemtype
{
	char name[30];
	char number[10];
	char introduce[50];
}Elemtype;
typedef struct Place
{
	int num;       //顶点位置序号
	Place *next;
	Elemtype date;    //顶点的信息内容
}Place;
typedef struct MGraph
{
	Place place;
	int legs[N][N];     //存放路径长度
}MGraph;
MGraph MGr;
int shortest[N][N];    //定义全局变量储存最短路径
int path[N][N];    //定义储存路径
Place *p;
void init(Place *&head)     //定义顶点位置及相关信息
{
	Place *p, *q;
	head = (Place *)malloc(sizeof(Place));
	head->next = NULL;
	q = head;
	p = (Place *)malloc(sizeof(Place));
	p->num = 1;
	strcpy_s(p->date.name, "一食堂");
	strcpy_s(p->date.number, "1");
	strcpy_s(p->date.introduce, "吃饭的地方");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 2;
	strcpy_s(p->date.name, "九教");
	strcpy_s(p->date.number, "2");
	strcpy_s(p->date.introduce, "计算机学院");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 3;
	strcpy_s(p->date.name, "五教");
	strcpy_s(p->date.number, "3");
	strcpy_s(p->date.introduce, "土木学院");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 4;
	strcpy_s(p->date.name, "六教");
	strcpy_s(p->date.number, "4");
	strcpy_s(p->date.introduce, "水环学院");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 5;
	strcpy_s(p->date.name, "礼堂");
	strcpy_s(p->date.number, "5");
	strcpy_s(p->date.introduce, "学生表演训练的地方");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 6;
	strcpy_s(p->date.name, "五公寓");
	strcpy_s(p->date.number, "6");
	strcpy_s(p->date.introduce, "女生公寓");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 7;
	strcpy_s(p->date.name, "七教");
	strcpy_s(p->date.number, "7");
	strcpy_s(p->date.introduce, "国教学院");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 8;
	strcpy_s(p->date.name, "四教");
	strcpy_s(p->date.number, "8");
	strcpy_s(p->date.introduce, "机电学院");
	p->next = q->next;
	q->next = p;
	q = p;
	//p = (Place *)malloc(sizeof(Place));
	//p->num = 9;
	//strcpy_s(p->date.name, "五实验楼");
	//strcpy_s(p->date.number, "9");
	//strcpy_s(p->date.introduce, "学生进行物理实验的地方");
	//p->next = q->next;
	//q->next = p;
	//q = p;
	//p = (Place *)malloc(sizeof(Place));
	//p->num = 10;
	//strcpy_s(p->date.name, "逸夫图书馆");
	//strcpy_s(p->date.number, "10");
	//strcpy_s(p->date.introduce, "学生进行自主学习的地方");
	//p->next = q->next;
	//q->next = p;
	//q = p;
	int i, j;      //定义顶点之间的距离
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			if (i == j)
				MGr.legs[i][j] = 0;
			else
				MGr.legs[i][j] = 0xffffff;
		}
	}
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			shortest[i][j] = MGr.legs[i][j];
	MGr.legs[1][6] = MGr.legs[6][1] = 24;
	MGr.legs[1][3] = MGr.legs[3][1] = 47;
	MGr.legs[1][5] = MGr.legs[5][1] = 70;
	MGr.legs[6][4] = MGr.legs[4][6] = 120;
	MGr.legs[3][4] = MGr.legs[4][3] = 88;
	MGr.legs[6][3] = MGr.legs[3][6] = 25;
	MGr.legs[3][5] = MGr.legs[5][3] = 23;
	MGr.legs[2][3] = MGr.legs[3][2] = 55;
	MGr.legs[3][7] = MGr.legs[7][3] = 66;
	MGr.legs[2][5] = MGr.legs[5][2] = 31;
	MGr.legs[5][7] = MGr.legs[7][5] = 42;
	MGr.legs[4][2] = MGr.legs[2][4] = 31;
	MGr.legs[2][7] = MGr.legs[7][2] = 74;
	MGr.legs[4][8] = MGr.legs[8][4] = 29;
	MGr.legs[2][8] = MGr.legs[8][2] = 79;
	MGr.legs[7][8] = MGr.legs[8][7] = 66;
}
void folyd()     //folyd算法求最短路径
{
	int i, j, k;
	for (i = 1; i <=8; i++)
	{
		for (j = 1; j <=8; j++)
		{
			shortest[i][j] = MGr.legs[i][j];
			path[i][j] = 0;
		}
	}
	for (k = 1; k <= 8; k++)
	{
		for (i = 1; i<=8; i++)
		{
			for (j = 1; j <8; j++)
			{
				if (shortest[i][j] > (shortest[i][k] + shortest[k][j]))
				{
					//cout << i << ' ' << j << ' ' << shortest[i][j] <<' '<<k<< endl;
					shortest[i][j] = shortest[i][k] + shortest[k][j];
					shortest[j][i] = shortest[i][k] + shortest[k][j];
					path[i][j] = k;
					path[j][i] = k;    //记录经过的路径
				}
			}
		}
	}
}
void dis(int i, int j)
{
	if (path[i][j] == 0)
		return;
	dis(i, path[i][j]);
	cout << "->"<<path[i][j];
	dis(path[i][j],j);
}
void display(int i, int j)     //输出两个顶点之间的路径及最短路径
{
	cout << "两位置之间的最短路径为：";
	cout << i;
	dis(i, j);
	cout << "->" << j << endl;
	cout <<"最短路径长度为:"<< shortest[i][j] << endl;
}
int shortdistance(Place *head)    //查找两顶点之间的最短路径
{
	int i, j;
	Place *t = head->next, *q = head->next;
	cout << "请输入要查找的两个位置的序号：" << endl;
	cin >> i >> j;
	while (t)
	{
		if (t->num == i)
			break;
		else
			t = t->next;
	}
	while (q)
	{
		if (q->num == j)
			break;
		else
			q = q->next;
	}
	if (q == NULL || t == NULL)
		cout << "抱歉，两位置之间没有路径！" << endl;
	else
	{
		folyd();
		display(i, j);
	}
	cout << endl;
	return 1;
}
void find(Place *&head)      //查询某位置的相关信息
{
	int n;
	Place *p = head;
	cout << "请输出查询位置的序号：";
	cout << endl;
	cin >> n;
	while (p->next)
	{
		if (p->next->num == n)
		{
			cout << "位置：" << p->next->num << endl;
			cout << "编号：" << p->next->date.number << endl;
			cout << "名称：" << p->next->date.name << endl;
			cout << "简介：" << p->next->date.introduce << endl;
			break;
		}
		else
			p = p->next;
	}
	if (p->next == NULL)
		cout << "该位置不存在！" << endl;
}
void menu()           //主菜单
{
	cout << "************************************" << endl;
	cout << "**************1.查询位置************" << endl;
	cout << "**************2.搜索路径************" << endl;
	cout << "**************3.退出系统************" << endl;
	cout << "************************************" << endl;
}
int main()           //主函数
{
	int x;
	init(p);
	while (1)
	{
		cout << "当前存在的位置个数为：" << Num << endl;
		cout << endl;
		menu();
		cin >> x;
		switch (x)
		{
		case 1:
			find(p); break;
		case 2:
			shortdistance(p); break;
		case 3:
			cout << "成功退出系统！" << endl;
			exit(0);
		}
	}
	system("pause");
	return 0;
}
