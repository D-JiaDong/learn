#include<iostream>
#include<queue>
using namespace std;
int n;
int num;
int sum;
struct pile
{
	int num;
	bool operator < (const pile &a) const {
		return  num > a.num;
	}
};
priority_queue <pile> pi;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pile p;
		cin >> p.num;
		pi.push(p);
	}
	while (!pi.empty())
	{
		int a = pi.top().num;
		pi.pop();
		if (!pi.empty())
		{
			int b = pi.top().num;
			pi.pop();
			pile p1; p1.num = a + b;
			pi.push(p1);
			sum += (a + b);
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

