#include<iostream>
#include<algorithm>
using namespace std;
int mx;
int n;
int val[30003];
int main()
{
	cin >> mx;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> val[i];
	sort(val, val + n);
	int L = 0;
	int cou = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (L > i)
			break;
		if (L == i)
		{
			cou++;
			break;
		}
		if (val[i] + val[L] <= mx)
		{
			L++;
			cou++;
		}
		else
			cou++;
	}
	cout << cou << endl;
	system("pause");
	return 0;
}