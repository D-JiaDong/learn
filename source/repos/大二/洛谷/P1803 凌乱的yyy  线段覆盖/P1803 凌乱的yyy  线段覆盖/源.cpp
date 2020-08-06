#include<iostream>
#include<algorithm>
using namespace std;
int n;
class ti
{
public:
	int st;
	int en;
};
ti t[1000002];
bool cmp(ti ti1,ti ti2)
{
	return ti1.st < ti2.st;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i].st >> t[i].en;
	sort(t, t + n, cmp);
	int sta = t[0].st, end = t[0].en;
	int cou = 1;
	for (int i = 1; i < n; i++)
	{
		if (t[i].st < end)
		{
			end = t[i].en < end ? t[i].en : end;
		}
		else
		{
			cou++;
			sta = t[i].st;
			end = t[i].en;
		}
	}
	cout << cou << endl;
	system("pause");
	return 0;
}