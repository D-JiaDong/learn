#include<iostream>
using namespace std;
int jishu(int a)
{
	/*if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else
	{

		int s = 0;
		for (int i = 0; i <= a / 2; i++)
		{
			s = s + jishu(i);
		}
		return s + 1;
	}*/
	int b[1001];
	b[0] = 0;
	b[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		int s = 0;
		for (int j = 0; j <= i / 2; j++)
			s = s + b[j];
		b[i] = s+1;
	}
	return b[a];
}
int main()
{
	int a;
	cin >> a;
	cout << jishu(a) << endl;
	system("pause");
	return 0;
}