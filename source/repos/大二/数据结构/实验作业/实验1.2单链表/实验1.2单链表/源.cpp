#include <iostream> 
#include<string>
using namespace std;
//定义数据类型
template <typename DataType>
class Node
{
public:
	DataType data; //数据域
	DataType jin='0';
	Node<DataType> *next;       //指针域
};
//定义单链表
template <typename DataType>
class LinkList
{
public:
	LinkList();                      //无参构造函数，建立只有头结点的空链表
	LinkList(DataType a[], int n);       //有参构造函数，建立有n个元素的单链表
	~LinkList();                     //析构函数
	int Length();                     //求单链表的长度
	Node<DataType> Get(int i);               //按位查找。查找第i个结点的元素值
	void Insert(int i,DataType x);       //插入操作，第i个位置插入值为x的结点
	void gai(int i, DataType n, DataType k);
	void PrintList();             //遍历操作，按序号依次输出各元素
private:
	Node<DataType> *first;           //单链表的头指针
};
//构造函数
template <typename DataType>
LinkList<DataType> ::LinkList()
{
	first = new Node<DataType>;              //生成头结点
	first->next = nullptr;                      //头结点的指针域置空
}
//析构函数
template <class DataType>
LinkList<DataType> :: ~LinkList()
{
	Node<DataType> *q = NULL;
	while (first != NULL)        //释放单链表的每一个结点的存储空间
	{
		q = first;                 //暂存被释放结点
		first = first->next;         // first指向被释放结点的下一个结点
		delete q;
	}
}
//输出链表
template <typename DataType>
void LinkList<DataType> ::PrintList()
{
	Node<DataType> *p = first->next;                //工作指针p初始化
	DataType a[20];
	int i = 0;
	while (p != nullptr)
	{
		a[i++] = p->data;
		//cout << p->data << "\t";
		p = p->next;                 //工作指针p后移，注意不能写作p++
	}
	for (int j = i-1; j >= 0; j--)
		cout << a[j];
	cout << endl;
}
//链表长度
template <typename DataType>
int LinkList<DataType> ::Length()
{
	Node<DataType> *p = first->next;   //工作指针p初始化为开始接点
	int count = 0;                    //累加器count初始化
	while (p != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;              //注意count的初始化和返回值之间的关系
}
//获取某一位置结点数据
template <typename DataType>
Node<DataType> LinkList<DataType> ::Get(int i)
{
	Node<DataType> *p = first->next;    //工作指针p初始化
	int count = 1;                     //累加器count初始化
	while (p != nullptr && count < i)
	{
		p = p->next;                   //工作指针p后移
		count++;
	}
	if (p == nullptr) throw "位置";
	else return *p;
}
//插入结点
template <typename DataType>
void LinkList<DataType> ::Insert(int i,DataType x)
{
	Node<DataType> *p = first, *s = nullptr;        //工作指针p初始化
	int count = 0;
	while (p != nullptr && count < i - 1)            //查找第i – 1个结点
	{
		p = p->next;                              //工作指针p后移
		count++;
	}
	if (p == nullptr) throw "位置";        //没有找到第i – 1个结点
	else {
		s = new Node<DataType>; s->data = x;      //申请结点s，数据域为x
		s->next = p->next; p->next = s;     //将结点s插入到结点p之后
	}
}
//含参构造函数
template <typename DataType>
LinkList<DataType> ::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;                    //生成头结点
	Node<DataType> *r = first, *s = nullptr;           //尾指针初始化
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; s->data = a[i];
		r->next = s; r = s;                 //将结点s插入到终端结点之后
	}
	r->next = nullptr;        //单链表建立完毕，将终端结点的指针域置空
}
//更改结点数据
template<typename DataType>
void LinkList<DataType>::gai(int i, DataType n, DataType k)
{
	Node<DataType> *p = first->next;    //工作指针p初始化
	int count = 1;                     //累加器count初始化
	while (p != nullptr && count < i)
	{
		p = p->next;                   //工作指针p后移
		count++;
	}
	if (p == nullptr) throw "位置";
	else
	{
		p->data = n;p->jin = k;
	}
}


int main()
{
	char er[20];            //定义数组存放二进制数

	//第一个二进制输入
	cout << "请输入第一个二进制数：" << endl;
	cin >> er;
	int len1 = strlen(er);  //存放二进制数长度

	//倒序第一个二进制数
	for (int i = 0; i < len1 / 2; i++)
	{
		char temp = er[i];
		er[i] = er[len1 - i - 1];
		er[len1 - i - 1] = temp;
	}                                
	LinkList<char> er1(er, len1);//含参构造函数构造第一个二进制链表
	
	//第二个二进制数输入（操作同上）
	cout << "请输入第二个二进制数：" << endl;
	cin >> er;
	int len2 = strlen(er);
	for (int i = 0; i < len2 / 2; i++)
	{
		char temp = er[i];
		er[i] = er[len2 - i - 1];
		er[len2 - i - 1] = temp;
	}
	LinkList<char> er2(er, len2);

	//定义指针链表类指针（p1存放较短二进制链表，p2存放较长二进制链表）
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
		//根据较短二进制数是否结束分两种相加方法
		if (off != 1)
			a = p1->Get(i).data + p2->Get(i).data + p2->Get(i).jin - 96;
		else
			a = p2->Get(i).data + p2->Get(i).jin-48;
		//判断较短二进制链表是否结束
		if (off == 0)
		{
			if (p1->Get(i).next == nullptr)
				off = 1;
		}
		//判断较长二进制链表是否结束，结束是在链表尾增加结点
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
		//根据对应位二进制相加结果判断是否进位并改变较长二进制链表的值
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
