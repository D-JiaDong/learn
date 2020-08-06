//#include<iostream>
//#include<cstdlib>
//using namespace std;
//#define sizestack 20
//class Stack
//{
//public:
//	char *base;
//	char *top;
//	int stackSize;
//}Stack1;
//void chushizhan(Stack *s)
//{
//	s->base = (char*)malloc(sizestack * sizeof(char));
//	if (!s->base)
//		exit(0);
//	s->top = s->base;
//	s->stackSize = sizestack;
//}
//void push(Stack *s, char e)
//{
//	if (s->top - s->base >= s->stackSize)
//	{
//		s->base = (char*)realloc(s->base, (s->stackSize + 10) * sizeof(char));
//
//	}
//	*(s->top) = e;
//	s->top++;
//}
//void pop(Stack *s, char *e)
//{
//	if (s->top == s->base)
//		return;
//	*e = *--(s->top);
//}
//int stacklen(Stack s)
//{
//	return (s.top - s.base);
//
//}
//int main()
//{
//	char c;
//	Stack s;
//	int len, i, sum = 0;
//	chushizhan(&s);
//	cout << "请输入二进制数，输入#符号表示结束" << endl;
//	cin >> c;
//	while (c != '#')
//	{
//		push(&s, c);
//		cin >> c;
//	}
//	getchar();//去掉\n;
//	len = stacklen(s);
//	cout <<"栈的当前容量是："<< len << endl;
//	for (int i = 0; i < len; i++)
//	{
//		pop(&s, &c);
//		sum += (c - 48)*pow(2, i);
//	}
//	cout << "转化为十进制为：" << sum << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
int er(int x)
{
	int a1[100];
	int i, j;
	int shang;
	for (i = 0; i < 100; i++)
	{
		if (x != 0)
		{
			a1[i] = x % 2;
			shang = x / 2;
			x = shang;
			j = i;
		}
		else
			break;

	}
	cout << "二进制:";
	for (i = j; i >= 0; i--)
		cout << a1[i];
	return 0;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "a:";
	er(a);
	cout << " ";
	cout << "b:";
	er(b);
	cout << endl;
	int c;
	while (0 != b)
	{
		c = a ^ b;//异或运算符，不进位
		b = (a&b) << 1;
		a = c;
		cout << "a:";
		er(a);
		cout << " ";
		cout << "b:";
		er(b);
		cout << endl;
	}
	cout << a;
	system("pause");
	return 0;
}
