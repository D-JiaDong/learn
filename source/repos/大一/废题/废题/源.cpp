#include<iostream>
#include<string>
using namespace std;
char a[256];
int main()
{
	cin >> a;
	int k = 0, i = 0,k1=0,k2=0;
	char c;
	while (a[k] != '@')
	{
		if (a[k] == '(' || a[k] == ')')
		{
			i++;
			if (a[k] == ')'&&i == 1)
			{
				cout << "NO" << endl;
				return 0;
			}
			else
			{
				if (a[k] == '(')
				{
					k1++;
					c = a[k];
				}
				else
				{
					k2++;
					c = a[k];
				}
				if (k2 - k1 >= 1)
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		k++;
	}
	if (c == '(')
		cout << "NO" << endl;
	else
	{
		if (k1 == k2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}