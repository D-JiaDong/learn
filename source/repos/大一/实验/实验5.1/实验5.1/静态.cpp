#include<iostream>
using namespace std;
class Student
{
public:
	static int n;
	static double all;
	double score;
	Student(double score)
	{
		++n;
		all = all + score;
	}
	static double pinjun()
	{
		return all / n;
	}

};
double Student::all = 0;
int Student::n = 0;
int main()
{
	Student s[2] = { Student(120),Student(130) };
	cout << Student::all << endl;
	cout << Student::pinjun() << endl;
	system("pause");
	return 0;
}