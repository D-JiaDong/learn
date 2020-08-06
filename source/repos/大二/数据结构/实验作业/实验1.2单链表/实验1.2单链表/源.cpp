#include <iostream> 
#include<string>
using namespace std;
//������������
template <typename DataType>
class Node
{
public:
	DataType data; //������
	DataType jin='0';
	Node<DataType> *next;       //ָ����
};
//���嵥����
template <typename DataType>
class LinkList
{
public:
	LinkList();                      //�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkList(DataType a[], int n);       //�вι��캯����������n��Ԫ�صĵ�����
	~LinkList();                     //��������
	int Length();                     //������ĳ���
	Node<DataType> Get(int i);               //��λ���ҡ����ҵ�i������Ԫ��ֵ
	void Insert(int i,DataType x);       //�����������i��λ�ò���ֵΪx�Ľ��
	void gai(int i, DataType n, DataType k);
	void PrintList();             //������������������������Ԫ��
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
//�������
template <typename DataType>
void LinkList<DataType> ::PrintList()
{
	Node<DataType> *p = first->next;                //����ָ��p��ʼ��
	DataType a[20];
	int i = 0;
	while (p != nullptr)
	{
		a[i++] = p->data;
		//cout << p->data << "\t";
		p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
	}
	for (int j = i-1; j >= 0; j--)
		cout << a[j];
	cout << endl;
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
//��ȡĳһλ�ý������
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
//������
template <typename DataType>
void LinkList<DataType> ::Insert(int i,DataType x)
{
	Node<DataType> *p = first, *s = nullptr;        //����ָ��p��ʼ��
	int count = 0;
	while (p != nullptr && count < i - 1)            //���ҵ�i �C 1�����
	{
		p = p->next;                              //����ָ��p����
		count++;
	}
	if (p == nullptr) throw "λ��";        //û���ҵ���i �C 1�����
	else {
		s = new Node<DataType>; s->data = x;      //������s��������Ϊx
		s->next = p->next; p->next = s;     //�����s���뵽���p֮��
	}
}
//���ι��캯��
template <typename DataType>
LinkList<DataType> ::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;                    //����ͷ���
	Node<DataType> *r = first, *s = nullptr;           //βָ���ʼ��
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; s->data = a[i];
		r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
	}
	r->next = nullptr;        //����������ϣ����ն˽���ָ�����ÿ�
}
//���Ľ������
template<typename DataType>
void LinkList<DataType>::gai(int i, DataType n, DataType k)
{
	Node<DataType> *p = first->next;    //����ָ��p��ʼ��
	int count = 1;                     //�ۼ���count��ʼ��
	while (p != nullptr && count < i)
	{
		p = p->next;                   //����ָ��p����
		count++;
	}
	if (p == nullptr) throw "λ��";
	else
	{
		p->data = n;p->jin = k;
	}
}


int main()
{
	char er[20];            //���������Ŷ�������

	//��һ������������
	cout << "�������һ������������" << endl;
	cin >> er;
	int len1 = strlen(er);  //��Ŷ�����������

	//�����һ����������
	for (int i = 0; i < len1 / 2; i++)
	{
		char temp = er[i];
		er[i] = er[len1 - i - 1];
		er[len1 - i - 1] = temp;
	}                                
	LinkList<char> er1(er, len1);//���ι��캯�������һ������������
	
	//�ڶ��������������루����ͬ�ϣ�
	cout << "������ڶ�������������" << endl;
	cin >> er;
	int len2 = strlen(er);
	for (int i = 0; i < len2 / 2; i++)
	{
		char temp = er[i];
		er[i] = er[len2 - i - 1];
		er[len2 - i - 1] = temp;
	}
	LinkList<char> er2(er, len2);

	//����ָ��������ָ�루p1��Ž϶̶���������p2��Žϳ�����������
	LinkList<char> *p1, *p2;
	if (er1.Length() < er2.Length())
	{
		p1 = &er1; p2 = &er2;
	}
	else
	{
		p2 = &er1; p1 = &er2;
	}

	char a;
	int off=0;
	for (int i = 1; i < p2->Length() + 1; i++)
	{
		//���ݽ϶̶��������Ƿ������������ӷ���
		if (off != 1)
			a = p1->Get(i).data + p2->Get(i).data + p2->Get(i).jin - 96;
		else
			a = p2->Get(i).data + p2->Get(i).jin-48;
		//�жϽ϶̶����������Ƿ����
		if (off == 0)
		{
			if (p1->Get(i).next == nullptr)
				off = 1;
		}
		//�жϽϳ������������Ƿ������������������β���ӽ��
		if (p2->Get(i).next == nullptr)
		{
			if (a < '2')
			{
				p2->gai(i, a, '0');
			}
			else
				p2->Insert(i, a - 2);
			break;
		}
		//���ݶ�Ӧλ��������ӽ���ж��Ƿ��λ���ı�ϳ������������ֵ
		if (a < '2')
		{
			p2->gai(i, a, '0');
		}
		else
		{
			p2->gai(i, a-2, '0');
			p2->gai(i+1, p2->Get(i+1).data, '1');
		}
	}
	p2->PrintList();
	p1->~LinkList(); 
	p2->~LinkList();
	system("pause");
	return 0;
}
