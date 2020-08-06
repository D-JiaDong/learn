#include<iostream>
using namespace std;
char num[12];
int main()
{
	int c;
	int i = 0;
	while (1)
	{
		c = getchar();
		if (c =='\n')
			break;
		else
			num[i++] = c;
	}
	int tp = 0;
	for(int n=0;n<i;n++)
		if (n != '0'&&n != '-')
		{
			tp = 1;
			break;
		}
	if (tp=='0')
	{
		cout << 0 << endl;
		system("pause");
		return 0;
	}
	if (num[0] == '-')
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (num[j] == '0')
				i--;
			else
				break;
		}
		for (int j = 1; j <=i / 2; j++)
		{
			char temp;
			temp = num[j];
			num[j] = num[i - j];
			num[i - j] = temp;
		}
		cout << '-';
		for (int k = 1; k < i; k++)
			cout << num[k];
		cout << endl;
	}
	else
	{
		for (int j = i - 1; j >=0; j-- )
		{
			if (num[j] == '0')
				i--;
			else
				break;
		}
		for (int j = 0; j <i/2; j++)
		{
			char temp;
			temp = num[j];
			num[j] = num[i - j - 1];
			num[i - j - 1] = temp;
		}
		for (int k = 0; k < i; k++)
			cout << num[k];
		cout << endl;
	}
	system("pause");
	return 0;
}