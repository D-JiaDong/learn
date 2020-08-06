#include <iostream>             
using namespace std;
//定义单项式数据类型
template <typename DataType>
class Node
{
public:
	DataType data;              //数据域
	DataType S;
	char X;
	DataType N;
	Node<DataType> *next;       //指针域
};
//定义单链表
template <typename DataType>
class LinkList
{
public:
	LinkList();                      //无参构造函数，建立只有头结点的空链表
	LinkList(Node<DataType> a[], int n);       //有参构造函数，建立有n个元素的单链表
	~LinkList();                     //析构函数
	int Length();                     //求单链表的长度
	void gai(int i, int n);
	Node<DataType> Get(int i);               //按位查找。查找第i个结点的元素值
	DataType Delete(int i);            //删除操作，删除第i个结点
	void PrintList();                  //遍历操作，按序号依次输出各元素
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
//链表的输出
template <typename DataType>
void LinkList<DataType> ::PrintList()
{
	Node<DataType> *p = first->next;                //工作指针p初始化
	while (p != nullptr)
	{
		if (p != first->next&&p->S > 0)
			cout << '+' << p->S << p->X << p->N;
		else
			cout<< p->S << p->X << p->N;
		p = p->next;                 //工作指针p后移，注意不能写作p++
	}
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
//获取某位置结点数据
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
//含参构造函数，为链表赋值
template <typename DataType>
LinkList<DataType> ::LinkList(Node<DataType> a[], int n)
{
	first = new Node<DataType>;                    //生成头结点
	Node<DataType> *r = first, *s = nullptr;           //尾指针初始化
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; s->S = a[i].S; s->X = a[i].X; s->N = a[i].N;
		r->next = s; r = s;                 //将结点s插入到终端结点之后
	}
	r->next = nullptr;        //单链表建立完毕，将终端结点的指针域置空
}
//删除结点
template <typename DataType>
DataType LinkList<DataType> ::Delete(int i)
{
	DataType x;
	Node<DataType> *p = first, *q = nullptr;        //工作指针p指向头结点
	int count = 0;
	while (p != nullptr && count < i - 1)           //查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p == nullptr || p->next == nullptr)  //结点p不存在或p的后继结点不存在
		throw "位置";
	else {
		q = p->next; x = q->data;         //暂存被删结点
		p->next = q->next;              //摘链
		delete q;
		return x;
	}
}
//更改结点数据
template <typename DataType>
void LinkList<DataType>::gai(int i, int n)
{
	Node<DataType> *p = first->next;    //工作指针p初始化
	int count = 1;                     //累加器count初始化
	while (p != nullptr && count < i)
	{
		p = p->next;                   //工作指针p后移
		count++;
	}
	if (p == nullptr) throw "位置";
	else  p->S=n;
}


int main()
{
	//第一个多项式数组
	Node<int> a[30];
	int i = 0;
	cout << "请输入第一个多项式" << endl;
	char c = '1';
	while (1)
	{
		cin >> a[i].S >> a[i].X >> a[i].N;
		if (c == '-')                          //特判减号
			a[i].S = 0 - a[i].S;
		 i++;
		 c = getchar();                      //获取运算符号
		if (c == '\n')                       //换行结束
			break;
	}
	LinkList<int> L1(a, i);//用含参构造函数构造链表


	//第二个多项式数组（同上）
	Node<int> b[30];
	int j = 0;
	cout << "请输入第2个多项式" << endl;
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


	//嵌套for循环实现两个多项式各单项式相乘
	Node<int> v[300];//定义新数组存放结果多项式
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


	//嵌套for循环实现同类项相加
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
	q.PrintList();//输出链表


	//析构函数
	L1.~LinkList(); L2.~LinkList(); q.~LinkList();
	system("pause");
	return 0;
}