#include<iostream>
#include<cmath>
using namespace std;
int a[5000001];
int n, k;
int n1 = 0;
int N = 0;
int sushu(int x)
{
	int su1 = 0;
	if (x <= 1)
		return 0;
	else
	{
		for (int i = 2; i <=sqrt(x); i++)
		{
			if (x%i == 0)
				su1++;
		}
		if (su1 == 0)
			return 1;
		else
			return 0;
	}
}
void huan(int a[], int i, int n1)
{
	int temp = a[n1];
	a[n1] = a[i];
	a[i] = temp;
}
void xuan(int a[], int n1, int n)
{
	if (n1 == k)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			//cout << a[i];
			sum += a[i];
		}
		//cout << endl;
		if (sushu(sum) == 1)
			N++;
	}
	for (int i = n1; i <n; i++)
	{
		huan(a, i, n1);
		xuan(a, n1 + 1, n);
		huan(a, i, n1);
	}
}
int jiecheng(int n)
{
	if (n == 1)
		return 1;
	else
		return n * jiecheng(n - 1);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	xuan(a, 0, n);
	//cout << endl;
	cout << N / jiecheng(k) << endl;
	system("pause");
	return 0;
}