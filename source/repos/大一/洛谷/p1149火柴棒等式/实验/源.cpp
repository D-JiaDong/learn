#include<iostream>
using namespace std;
int main()
{
	int huocha(int b);
	int n, n1=0;
	cin >> n;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			if (huocha(i) + huocha(j) + huocha(i + j) == n - 4)
			{
				cout << i << "+" << j << "=" << i + j << endl;
				n1++;
			}
	cout << n1 <<endl;
	system("pause");
	return 0;
}
int huocha(int b)
{
	int a[10] = { 6,2,5,5,4,5,6,3,7,6 };
	if (b < 10)
		return a[b];
	else if (b < 100)
	{
		int shiwei = b / 10;
		int gewei = b - shiwei * 10;
		return a[shiwei] + a[gewei];
	}
	else if (b < 1000)
	{
		int baiwei = b / 100;
		int shiwei = (b - baiwei * 100) / 10;
		int gewei = b - baiwei * 100 - shiwei * 10;
		return a[baiwei] + a[shiwei] + a[gewei];
	}
	else if (b < 10000)
	{
		int qianwei = b / 1000;
		int baiwei = (b - qianwei * 1000) / 100;
		int shiwei = (b - qianwei * 1000 - baiwei * 100) / 10;
		int gewei = b - qianwei * 1000 - baiwei * 100 - shiwei * 10;
		return a[qianwei] + a[baiwei] + a[shiwei] + a[gewei];
	}
	else
	{
		cout << "能力有限..." << endl;
		return 0;
	}
}