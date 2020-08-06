#pragma once
#include"БъЭЗ.h"
inline Teacher::Teacher(string nam, int ag, string se, string ad, string p, string titl)
{
	name = nam;
	age = ag;
	sex = se;
	add = ad;
	ph = p;
	title = titl;
	cout << "2..." << endl;
}
inline void Teacher::display()
{
	cout << name << age << sex << add << ph << title << endl;
}
inline Cadre::Cadre(string nam, int ag, string se, string ad, string p, string pos)
{
	name = nam;
	age = ag;
	sex = se;
	add = ad;
	ph = p;
	post = pos;
	cout << "3..." << endl;
}
inline Teacher_Cadre::Teacher_Cadre(string name, int age, string sex, string add, string ph, string title, string post, double wage) :
	Teacher(name, age, sex, add, ph, title),
	Cadre(name, age, sex, add, ph, post)
{
	wages = wage;
	cout << "1..." << endl;
}
inline void Teacher_Cadre::show(Teacher_Cadre B)
{
	B.display();
}

