#include<iostream>
#include<string>
using namespace std;
class Teacher
{
protected:
	string name;
	int age;
	string sex;
	string add;
	string ph;
	string title;
public:
	Teacher(string nam, int ag, string sex, string ad, string p, string titl);
	void display();
};
class Cadre
{
public:
	string name;
	int age;
	string sex;
	string add;
	string ph;
	string post;
	Cadre(string nam, int ag, string se, string ad, string p, string pos);
};
class Teacher_Cadre :public Teacher, public Cadre
{
public:
	double wages;
	Teacher_Cadre(string name, int age, string sex, string add, string ph, string title, string post, double wage);
	void show(Teacher_Cadre	B);
	void print();
};
inline Teacher::Teacher(string nam, int ag, string se, string ad, string p, string titl)
{
	name = nam;
	age = ag;
	sex = se;
	add = ad;
	ph = p;
	title = titl;
}
inline void Teacher::display()
{
	cout <<"姓名:"<<name <<endl<<"年龄:"<< age<<endl <<"性别:" <<sex<<endl <<
		"地址:"<<add <<endl<<"电话:"<<ph<<endl<<"职称:"<< title << endl;
}
inline Cadre::Cadre(string nam, int ag, string se, string ad, string p, string pos)
{
	name = nam;
	age = ag;
	sex = se;
	add = ad;
	ph = p;
	post = pos;
}
inline Teacher_Cadre::Teacher_Cadre(string name, int age, string sex, string add, string ph, string title, string post, double wage) :
	Teacher(name, age, sex, add, ph, title),
	Cadre(name, age, sex, add, ph, post)
{
	wages = wage;

}
inline void Teacher_Cadre::print()
{
	cout << "教师兼干部:";
	cout << endl;
}
inline void Teacher_Cadre::show(Teacher_Cadre B)
{
	B.display();
}
int main()
{
	Teacher_Cadre a("张三", 34, "男", "长春市", "111110", "教授", "院长", 20000);
	a.print();
	a.show(a);
	cout << "职务:"<<a.post << endl<< "工资:"<<a.wages << endl;
	system("pause");
	return 0;
}