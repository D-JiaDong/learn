#include<iostream>
using namespace std;
char a[501][501];
int b[501][501], c[4][2] = { 1,0,0,1,0,-1,-1,0 };
int m, n,N;
void digui(int x, int y)
{
	if (x < 0 || y < 0 || x >m+1 || y >n+1 || a[x][y] == '*')
		return;
	a[x][y] = '*';
	for (int i = 0; i < 4; i++)
		digui(x + c[i][0], y + c[i][1]);
}
//void digui1(int x,int y)
//{
//	if (x < 0 || y < 0 || x >m + 1 || y >n + 1 || a[x][y] == '*'||b[x][y]==1)
//		return;
//	b[x][y] = 1;
//	int k = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		int x0, y0;
//		x0 = x + c[i][0]; y0 = y + c[i][1];
//		if (a[x0][y0] == 2 || b[x0][y0] == 1)
//			k++;
//	}
//	if (k != 0)
//		a[x][y] = 2;
//	for (int i = 0; i < 4; i++)
//		digui(x + c[i][0], y + c[i][1]);
//}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	digui(0, 0);
	/*for (int i = 0; i <= m+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
			cout<< a[i][j]<<" ";
		cout << endl;
	}*/
	/*for (int i = 0; i <= m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			digui1(i, j);*/
	/*for (int i = 0; i <= m + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}*/
	for (int i = 0; i <= m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (a[i][j] == '0')
				N++;
	cout << N << endl;
	system("pause");
	return 0;
}