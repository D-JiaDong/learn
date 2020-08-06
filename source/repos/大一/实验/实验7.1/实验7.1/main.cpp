#include <iostream>
#include <string>
using namespace std;
class Student            //定义基类
{
public:
	Student(int, string, float);
	virtual void Display();      //声明输出函数
protected:           //受保护成员，派生类可访问
	int num;
	string name;
	float score;
};
Student::Student(int n, string nam, float s)
{
	num = n; name = nam; score = s;
}
void Student::Display()
{
	cout << "num:"<< num << "name:" << name << "score:" << score << endl << endl;
}
class Graduate :public Student  //声明公有派生类
{
public:
	Graduate(int, string, float, float);
	void Display();               //声明输出函数
private:
	float pay;
};
Graduate::Graduate(int n, string nam, float s, float p) :Student(n, nam, s), pay(p) {}
void Graduate::Display()
{
	cout << "num:"<< num << "name:"<< name <<"score:"<< score << "pay ="<< pay << endl;
}
void main()
{
	Student stud(1001, "Li", 87.5);
	Graduate grad(2001, "Wang", 98.5, 563.5);
	Student *pt = &stud;
	pt->Display();
	pt = &grad;
	pt->Display();
	system("pause");
}
