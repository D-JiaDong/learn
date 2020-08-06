#include<iostream>
using namespace std;
struct GRADE
{
	int Id;
	int chinese;
	int math;
	int english;
	int total;
};
bool compare(const GRADE &a, const GRADE &b)
{
	if (a.total == b.total)
	{
		return a.chinese > b.chinese;
	}
	if (a.total == b.total && a.chinese == b.chinese)
	{
		return a.Id < b.Id;
	}
	return a.total > b.total;
}
int main()
{
	int num;
	cin >> num;
	GRADE Grade[300];
	for (int i = 0; i < num; i++)
	{
		Grade[i].Id = i + 1;
		cin >> Grade[i].chinese;
		cin >> Grade[i].math;
		cin >> Grade[i].english;
		Grade[i].total = Grade[i].chinese + Grade[i].math + Grade[i].english;
	}
	sort(Grade, grade + num, compare);
	for (int i = 0; i < 5; i++)
	{
		cout << Grade[i].Id << "" << Grade[i].total << endl;
	}
}
