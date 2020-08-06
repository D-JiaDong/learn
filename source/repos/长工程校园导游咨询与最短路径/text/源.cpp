#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 11   //��󶥵����
#define Road 100   //���·��
int Num = 10;     //Ŀǰ�������
using namespace std;
typedef struct Elemtype
{
	char name[30];
	char number[10];
	char introduce[50];
}Elemtype;
typedef struct Place
{
	int num;       //����λ�����
	Place *next;
	Elemtype date;    //�������Ϣ����
}Place;
typedef struct MGraph
{
	Place place;
	int legs[N][N];     //���·������
}MGraph;
MGraph MGr;
int shortest[N][N];    //����ȫ�ֱ����������·��
int path[N][N];    //���崢��·��
Place *p;
void init(Place *&head)     //���嶥��λ�ü������Ϣ
{
	Place *p, *q;
	head = (Place *)malloc(sizeof(Place));
	head->next = NULL;
	q = head;
	p = (Place *)malloc(sizeof(Place));
	p->num = 1;
	strcpy_s(p->date.name, "һʳ��");
	strcpy_s(p->date.number, "1");
	strcpy_s(p->date.introduce, "�Է��ĵط�");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 2;
	strcpy_s(p->date.name, "�Ž�");
	strcpy_s(p->date.number, "2");
	strcpy_s(p->date.introduce, "�����ѧԺ");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 3;
	strcpy_s(p->date.name, "���");
	strcpy_s(p->date.number, "3");
	strcpy_s(p->date.introduce, "��ľѧԺ");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 4;
	strcpy_s(p->date.name, "����");
	strcpy_s(p->date.number, "4");
	strcpy_s(p->date.introduce, "ˮ��ѧԺ");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 5;
	strcpy_s(p->date.name, "����");
	strcpy_s(p->date.number, "5");
	strcpy_s(p->date.introduce, "ѧ������ѵ���ĵط�");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 6;
	strcpy_s(p->date.name, "�幫Ԣ");
	strcpy_s(p->date.number, "6");
	strcpy_s(p->date.introduce, "Ů����Ԣ");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 7;
	strcpy_s(p->date.name, "�߽�");
	strcpy_s(p->date.number, "7");
	strcpy_s(p->date.introduce, "����ѧԺ");
	p->next = q->next;
	q->next = p;
	q = p;
	p = (Place *)malloc(sizeof(Place));
	p->num = 8;
	strcpy_s(p->date.name, "�Ľ�");
	strcpy_s(p->date.number, "8");
	strcpy_s(p->date.introduce, "����ѧԺ");
	p->next = q->next;
	q->next = p;
	q = p;
	//p = (Place *)malloc(sizeof(Place));
	//p->num = 9;
	//strcpy_s(p->date.name, "��ʵ��¥");
	//strcpy_s(p->date.number, "9");
	//strcpy_s(p->date.introduce, "ѧ����������ʵ��ĵط�");
	//p->next = q->next;
	//q->next = p;
	//q = p;
	//p = (Place *)malloc(sizeof(Place));
	//p->num = 10;
	//strcpy_s(p->date.name, "�ݷ�ͼ���");
	//strcpy_s(p->date.number, "10");
	//strcpy_s(p->date.introduce, "ѧ����������ѧϰ�ĵط�");
	//p->next = q->next;
	//q->next = p;
	//q = p;
	int i, j;      //���嶥��֮��ľ���
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
void folyd()     //folyd�㷨�����·��
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
					path[j][i] = k;    //��¼������·��
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
void display(int i, int j)     //�����������֮���·�������·��
{
	cout << "��λ��֮������·��Ϊ��";
	cout << i;
	dis(i, j);
	cout << "->" << j << endl;
	cout <<"���·������Ϊ:"<< shortest[i][j] << endl;
}
int shortdistance(Place *head)    //����������֮������·��
{
	int i, j;
	Place *t = head->next, *q = head->next;
	cout << "������Ҫ���ҵ�����λ�õ���ţ�" << endl;
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
		cout << "��Ǹ����λ��֮��û��·����" << endl;
	else
	{
		folyd();
		display(i, j);
	}
	cout << endl;
	return 1;
}
void find(Place *&head)      //��ѯĳλ�õ������Ϣ
{
	int n;
	Place *p = head;
	cout << "�������ѯλ�õ���ţ�";
	cout << endl;
	cin >> n;
	while (p->next)
	{
		if (p->next->num == n)
		{
			cout << "λ�ã�" << p->next->num << endl;
			cout << "��ţ�" << p->next->date.number << endl;
			cout << "���ƣ�" << p->next->date.name << endl;
			cout << "��飺" << p->next->date.introduce << endl;
			break;
		}
		else
			p = p->next;
	}
	if (p->next == NULL)
		cout << "��λ�ò����ڣ�" << endl;
}
void menu()           //���˵�
{
	cout << "************************************" << endl;
	cout << "**************1.��ѯλ��************" << endl;
	cout << "**************2.����·��************" << endl;
	cout << "**************3.�˳�ϵͳ************" << endl;
	cout << "************************************" << endl;
}
int main()           //������
{
	int x;
	init(p);
	while (1)
	{
		cout << "��ǰ���ڵ�λ�ø���Ϊ��" << Num << endl;
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
			cout << "�ɹ��˳�ϵͳ��" << endl;
			exit(0);
		}
	}
	system("pause");
	return 0;
}
