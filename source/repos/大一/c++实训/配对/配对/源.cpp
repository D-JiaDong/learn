#include<iostream>
using namespace std;
int a[100];
int qiuzhi(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return qiuzhi(n - 2) + qiuzhi(n - 1) + 1;
}
int main()
{
	int n[101], n1[101]; int k = 0;
	for (int i = 0; i < 101; i++)
	{
		cin >> n[i];
		if (n[i] == 0)
			break;
		n1[i] = qiuzhi(n[i]);
		k++;
	}
	for (int i = 0; i < k; i++)
		cout << n1[i] << endl;
	system("pause");
	return 0;
}