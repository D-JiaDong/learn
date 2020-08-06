#include<iostream>
using namespace std;
int ncifang(double b)
{
	if (b == 0)
		return 1;
	else
	{
		int j;
		j = b;
		j = 10 * ncifang(j - 1);
		return j;
		cout << j;
	}
}
int weishu(double x)
{
	int i, n;
	for (i = 0; i < 10; i++)
		if (x / ncifang(i) < 10)
		{
			n = i;
			break;
		}
	return n+1;
}
int main()
{
	int a;
	cin >>a;
	cout<<weishu(a);
	system("pause");
	return 0;
}