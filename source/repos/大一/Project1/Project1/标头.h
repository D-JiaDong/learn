#pragma once
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
	Teacher_Cadre(string name, int age, string sex, string ad, string ph, string title, string post, double wage);
	void show(Teacher_Cadre B);
};