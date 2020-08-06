#include <iostream>             
using namespace std;
//���嵥��ʽ��������
template <typename DataType>
class Node
{
public:
	DataType data;              //������
	DataType S;
	char X;
	DataType N;
	Node<DataType> *next;       //ָ����
};
//���嵥����
template <typename DataType>
class LinkList
{
public:
	LinkList();                      //�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkList(Node<DataType> a[], int n);       //�вι��캯����������n��Ԫ�صĵ�����
	~LinkList();                     //��������
	int Length();                     //������ĳ���
	void gai(int i, int n);
	Node<DataType> Get(int i);               //��λ���ҡ����ҵ�i������Ԫ��ֵ
	DataType Delete(int i);            //ɾ��������ɾ����i�����
	void PrintList();                  //������������������������Ԫ��
private:
	Node<DataType> *first;           //�������ͷָ��
};
//���캯��
template <typename DataType>
LinkList<DataType> ::LinkList()
{
	first = new Node<DataType>;              //����ͷ���
	first->next = nullptr;                      //ͷ����ָ�����ÿ�
}
//��������
template <class DataType>
LinkList<DataType> :: ~LinkList()
{
	Node<DataType> *q = NULL;
	while (first != NULL)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		q = first;                 //�ݴ汻�ͷŽ��
		first = first->next;         // firstָ���ͷŽ�����һ�����
		delete q;
	}
}
//��������
template <typename DataType>
void LinkList<DataType> ::PrintList()
{
	Node<DataType> *p = first->next;                //����ָ��p��ʼ��
	while (p != nullptr)
	{
		if (p != first->next&&p->S > 0)
			cout << '+' << p->S << p->X << p->N;
		else
			cout<< p->S << p->X << p->N;
		p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
	}
}
//������
template <typename DataType>
int LinkList<DataType> ::Length()
{
	Node<DataType> *p = first->next;   //����ָ��p��ʼ��Ϊ��ʼ�ӵ�
	int count = 0;                    //�ۼ���count��ʼ��
	while (p != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;              //ע��count�ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ
}
//��ȡĳλ�ý������
template <typename DataType>
Node<DataType> LinkList<DataType> ::Get(int i)
{ 
	Node<DataType> *p = first->next;    //����ָ��p��ʼ��
	int count = 1;                     //�ۼ���count��ʼ��
	while (p != nullptr && count < i)
	{
		p = p->next;                   //����ָ��p����
		count++;
	}
	if (p == nullptr) throw "λ��";
	else return *p;
}
//���ι��캯����Ϊ����ֵ
template <typename DataType>
LinkList<DataType> ::LinkList(Node<DataType> a[], int n)
{
	first = new Node<DataType>;                    //����ͷ���
	Node<DataType> *r = first, *s = nullptr;           //βָ���ʼ��
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; s->S = a[i].S; s->X = a[i].X; s->N = a[i].N;
		r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
	}
	r->next = nullptr;        //����������ϣ����ն˽���ָ�����ÿ�
}
//ɾ�����
template <typename DataType>
DataType LinkList<DataType> ::Delete(int i)
{
	DataType x;
	Node<DataType> *p = first, *q = nullptr;        //����ָ��pָ��ͷ���
	int count = 0;
	while (p != nullptr && count < i - 1)           //���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p == nullptr || p->next == nullptr)  //���p�����ڻ�p�ĺ�̽�㲻����
		throw "λ��";
	else {
		q = p->next; x = q->data;         //�ݴ汻ɾ���
		p->next = q->next;              //ժ��
		delete q;
		return x;
	}
}
//���Ľ������
template <typename DataType>
void LinkList<DataType>::gai(int i, int n)
{
	Node<DataType> *p = first->next;    //����ָ��p��ʼ��
	int count = 1;                     //�ۼ���count��ʼ��
	while (p != nullptr && count < i)
	{
		p = p->next;                   //����ָ��p����
		count++;
	}
	if (p == nullptr) throw "λ��";
	else  p->S=n;
}


int main()
{
	//��һ������ʽ����
	Node<int> a[30];
	int i = 0;
	cout << "�������һ������ʽ" << endl;
	char c = '1';
	while (1)
	{
		cin >> a[i].S >> a[i].X >> a[i].N;
		if (c == '-')                          //���м���
			a[i].S = 0 - a[i].S;
		 i++;
		 c = getchar();                      //��ȡ�������
		if (c == '\n')                       //���н���
			break;
	}
	LinkList<int> L1(a, i);//�ú��ι��캯����������


	//�ڶ�������ʽ���飨ͬ�ϣ�
	Node<int> b[30];
	int j = 0;
	cout << "�������2������ʽ" << endl;
	char c1 = '1';
	while (1)
	{
		cin >> b[j].S >> b[j].X >> b[j].N;
		if (c1 == '-')
			b[j].S = 0 - b[j].S;
		j++;
	    c1 = getchar();
		if (c1== '\n')
			break;
	}
	LinkList<int> L2(b, j);


	//Ƕ��forѭ��ʵ����������ʽ������ʽ���
	Node<int> v[300];//�����������Ž������ʽ
	int v1 = 0;
	for (int i = 0; i <L1.Length(); i++)
	{
		Node<int> a = L1.Get(i + 1);
		for (int j = 0; j < L2.Length(); j++)
		{
			Node<int> b = L2.Get(j + 1);
			v[v1].S = a.S*b.S; v[v1].X = a.X; v[v1].N = a.N + b.N;
			v1++;
		}
	}
    LinkList<int> q(v, v1);


	//Ƕ��forѭ��ʵ��ͬ�������
	for (int i = 0; i <q.Length(); i++)
	{
		Node<int> a = q.Get(i + 1);
		for (int j = i+1; j < q.Length(); j++)
		{
			Node<int> b = q.Get(j + 1);
			if (b.N == a.N)
			{
				//cout << j+1 <<" "<<b.S+a.S<< endl;
				q.gai(i+1, b.S + a.S);
				a = q.Get(i + 1);
				q.Delete(j+1);
			}
		}
	}
	q.PrintList();//�������


	//��������
	L1.~LinkList(); L2.~LinkList(); q.~LinkList();
	system("pause");
	return 0;
}