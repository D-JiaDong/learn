#include<iostream>
using namespace std;
int a[33][33][2];
int c[4][2] = {0,-1,0,1,-1,0,1,0};
int n;
void digui(int x,int y)
{
	if (x<0||y<0|| x>n+1 || y>n+1 || a[x][y][0] != 0||a[x][y][1]==1)
		return;
	a[x][y][1] = 1;
	for (int i = 0; i <4; i++)
	{
		int x0, y0;
		x0 = x + c[i][0];
		y0 = y + c[i][1];
		digui(x0, y0);
	/*	digui(c[i][0] + x, c[i][1] + y);*/
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j][0];
			if (a[i][j][0] == 1)
				a[i][j][1] = 1;
		}
	/*cout << endl;
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
			cout << a[i][j][1] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
			cout << a[i][j][0] << " ";
		cout << endl;
	}
	cout << endl;*/
	digui(0, 0);
	/*for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
			cout << a[i][j][1] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
			cout << a[i][j][0] << " ";
		cout << endl;
	}
	cout << endl;*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (a[i][j][1] == 1)
				cout << a[i][j][0] << " ";
			else
				cout << 2 << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}