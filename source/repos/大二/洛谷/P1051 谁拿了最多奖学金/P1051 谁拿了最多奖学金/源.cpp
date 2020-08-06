#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	double qmave;
	double pyave;
	char x; char s;
	int lw;
	int sum=0;
public:
	Student(string name, double qmave, double pyave, char x, char s,int lw)
	{
		this->name = name; this->qmave = qmave; this->pyave = pyave; this->x = x; this->s = s; this->lw = lw;
	}
	int scholarship()
	{
		if (sum != 0)
			return sum;
		if (qmave > 80 && lw >= 1)
			sum += 8000;
		if (qmave > 85 && pyave > 80)
			sum += 4000;
		if (qmave > 90)
			sum += 2000;
		if (qmave > 85 && s == 'Y')
			sum += 1000;
		if (pyave > 80 && x == 'Y')
			sum += 850;
		return sum;
	}
};
int main()
{
	string name,name1;
	double qmave;
	double pyave;
	char x; char s;
	int lw;
	int n;
	cin >> n;
	int ship=0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> qmave >> pyave >> x >> s >> lw;
		Student student(name, qmave, pyave, x, s, lw);
		if (student.scholarship() > ship)
		{
			ship = student.scholarship();
			name1 = name;
		}
		sum += student.scholarship();
	}
	cout << name1 << endl << ship << endl<< sum << endl;
	system("pause");
	return 0;
}