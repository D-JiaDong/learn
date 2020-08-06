#include<iostream>
using namespace std;
int main()
{
	void xiaoshu(char a[]);
	char a[10];
	int i;
	cout << "请输入一个数" << endl;
	cin >> a;
	for (i = 0; i < 10; i++)
	{
		if (a[i] == '.')
		{
			xiaoshu(a);
		}
	}
	system("pause");
	return 0;
}
void xiaoshu(char a[])
{
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		if (a[i] != '0' && a[i] != '.')
		{
			j = i;
			break;
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] == '\0')
			k = i;
	}
	if (k - j == 3)
		cout << a << endl;
	else
		if (k - j < 3)
		{
			cout << a;
			for (i = k - j; i < 3; i++)
				cout << '0';
		}
		else
			if (a[j + 3] =='5')
				if (k - j == 4)
					if (a[j + 2] == '1')
						for (i = 0; i < j + 3; i++)
							cout << a[i];
				
}
//void zhengshu(char a[])
//{}
