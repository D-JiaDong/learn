#include<iostream>
#include <string.h>
using namespace std;
class Person
{
	static int total;
	static int Max_number;
public:
	Person();
	static void display()
	{
		cout << " total = " << total << endl;
		cout << "Max_number:" << Max_number << endl;
	}
	void print_no()
	{
		cout << S_number << endl;
	}
private:
	char *name;
	int S_number;
};
Person::Person()
{
	char a[10];
	name = a;
	total++;
	S_number = 999 + total;
	Max_number = S_number;
	cout << "请输入第" << total << "个员工姓名" << endl;
	cin >> a;
	cout << a << ":" << S_number<<endl;
}
int Person::total = 0;
int Person::Max_number = 0;
void main()
{
	Person p1, p2, p3, p4;
	Person::display();
	p4.display();
	p3.print_no();
	system("pause");
}
