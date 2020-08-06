#include<iostream>
using namespace std;
class shuzi
{
public:
	int m;
	int print()
	{
		cout << "请输入一个十进制数" << endl;
		cin >> m;
		return m;
	}
	friend int er(int x);
	friend int ba(int x);
	friend int shiliu(int x);
}shuzi1;
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
		cout << a1[i] ;
	cout << endl;
	return 0;
}
int ba(int x)
{
	int a1[100];
	int i, j;
	int shang;
	for (i = 0; i < 100; i++)
	{
		if (x != 0)
		{
			a1[i] = x % 8;
			shang = x/ 8;
			x = shang;
			j = i;
		}
		else
			break;

	}
	cout << "八进制:";
	for (i = j; i >= 0; i--)
		cout << a1[i] ;
	cout << endl;
	return 0;
}
char zimu(int x)
{
	if (x == 10)
		return 'a';
	else if (x == 11)
		return 'b';
	else if (x == 12)
		return 'c';
	else if (x == 13)
		return 'd';
	else if (x == 14)
		return 'e';
	else if (x == 15)
		return 'f';
	else
		return 'g';
}
int shiliu(int x)
{
	int a1[100];
	int i, j;
	int shang;
	for (i = 0; i < 100; i++)
	{
		if (x != 0)
		{
			a1[i] = x % 16;
			shang = x / 16;
			x = shang;
			j = i;
		}
		else
			break;
	}
	for (i = j; i >= 0; i--)
		if (a1[i] < 10)
			cout << a1[i];
		else
			cout << zimu(a1[i]);
	cout << endl;
	return 0;
}
int main()
{
	int er(int x);
	int ba(int x);
	int shiliu(int x);
	char zimu(int x);
	shuzi1.print();
	er(shuzi1.m);
	ba(shuzi1.m);
	cout << "十六进制:";
	shiliu(shuzi1.m);
	system("pause");
	return 0;
}
