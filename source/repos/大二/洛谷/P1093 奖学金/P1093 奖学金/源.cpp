#include<iostream>
using namespace std;
double c[5], m[5], e[5], s[5],b[5];
class Student
{
private:
	double Chinese;
	double Math;
	double English;
public:
	Student(double Chinese, double Math, double English)
	{
		this->Chinese = Chinese; this->Math = Math, this->English = English;
	}
	double Sum()
	{
		return Chinese + Math + English;
	}
};
int main()
{
	double Chinese, Math, English;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Chinese >> Math >> English;
		Student student(Chinese, Math, English);
		for (int j = 0; j < 5; j++)
		{
			if (student.Sum() > s[j] || (student.Sum() == s[j] && Chinese > c[j]))
			{
				for (int k = 4; k >j; k--)
				{
					c[k] = c[k - 1]; m[k] = m[k - 1]; e[k] = e[k - 1]; s[k] = s[k - 1];b[k]=b[k-1];
				}
				c[j] = Chinese, m[j] = Math, e[j] = English, s[j] = student.Sum();b[j]=i+1;
				break;
			}
		}

	}
	for (int i = 0; i < 5; i++)
		cout << b[i] << " " << s[i] << endl;
	system("pause");
	return 0;
}