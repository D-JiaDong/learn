#include<iostream>
using namespace std;
class A
{
public:
	A() 
	{
		cout << "nihao1" << endl;
	}
	~A()
	{
		cout << "buhao1" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "nihao2" << endl;
	}
	~B()
	{
		cout << "buhao2" << endl;
	}
};
int main()
{
	A a;
	B b;
	//system("pause");
	return 0;
}