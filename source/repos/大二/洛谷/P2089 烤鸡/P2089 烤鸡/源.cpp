#include<iostream>
using namespace std;
int burden[10];
int fang[10000][10];
int n,j;
void xhdg(int ceng,int sum)
{
	if (ceng ==10)
	{
		if (sum == n) 
		{
			for (int i = 0; i < 10; i++)
				fang[j][i] = burden[i];
			j++;
		}
		return;
	}
	if (sum >= n) return;
	for (int i = 1; i <= 3; i++)
	{
		burden[ceng] = i;
		xhdg(ceng + 1, sum + i);
	}
}
int main()
{
	cin >> n;
	if (n < 10 || n>30)
		cout << "0" << endl;
	else
	{
		xhdg(0, 0);
		cout << j << endl;
		for (int i = 0; i < j; i++)
		{
			for (int k = 0; k < 10; k++)
				cout << fang[i][k] << ' ';
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
