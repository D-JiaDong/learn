#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 0; i--)
		if (a[n - i] != 0)
		{
			if (i != n && a[n - i] > 0)
				cout << '+';
			if ((a[n - i] != 1 && a[n - i] != -1) || i == 0)
			   cout << a[n - i];
			if (a[n - i] == -1&&i!=0)
				cout << '-';
			if (i  != 0 && i != 1)
				cout << "x^" << i;
			if (i  == 1)
				cout << 'x';
		}
	system("pause");
	return 0;
}
