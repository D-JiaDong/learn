//#include<iostream>
//using namespace std;
//char  a[1004][1004],b[1004][1004];
//int t[4][2] = { 1,0,0,1,-1,0,0,-1 };
//int m, n;
//int nu[100004];
//int ans[100004];
//void dfs(int x, int y, int nu1)
//{
//	if (x < 0 || y < 0 || x >= n || y >= n)
//		return;
//	nu[nu1]++;
//	b[x][y] = nu1+48;
//	/*for (int k = 0; k < n; k++)
//		for (int j = 0; j < n; j++)
//			cout << b[k][j];
//	cout <<x<<y<<" "<<b[x][y] << endl;*/
//	for (int i = 0; i < 4; i++)
//	{
//		int x1 = x + t[i][0];
//		int y1 = y + t[i][1];
//		if (b[x1][y1] == nu1 + 48 || a[x1][y1] == a[x][y])
//			continue;
//		else
//			if (b[x][y] != '\0')
//			{
//				if (ans[b[x][y] - 48] != 0)
//				{
//					nu[nu1] = ans[b[x][y] - 48];
//					return;
//				}
//			}
//			else
//				dfs(x1, y1, nu1);
//	}
//}
//int main()
//{
//	//cout << b[0][0] << endl;
//	int x, y;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//	for (int i = 0; i < m; i++)
//	{
//		cin >> x >> y;
//		dfs(x - 1, y - 1, i);
//		ans[i] = nu[i];
//		/*for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				cout << b[i][j];
//			cout << endl;
//		}*/
//	}
//	for (int i = 0; i < m; i++)
//		cout << ans[i] << endl;
//	//cout << x << y << n << m << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
char  a[1004][1004];
int t[4][2] = { 1,0,0,1,-1,0,0,-1 }, b[1004][1004];
int m, n;
int nu[100004];
int ans[100004];
void dfs(int x, int y, int nu1)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;
	nu[nu1]++;
	b[x][y] = nu1+1;
	/*for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
			cout << b[k][j];
	cout <<x<<y<<" "<<b[x][y] << endl;*/
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + t[i][0];
		int y1 = y + t[i][1];
		if (b[x1][y1] == nu1+1 || a[x1][y1] == a[x][y])
			continue;
		else
			if (b[x1][y1] != 0)
			{
				if (ans[b[x1][y1]-1] != 0)
				{
					nu[nu1] = ans[b[x1][y1]-1];
				}
			}
			else
				dfs(x1, y1, nu1);
	}
}
int main()
{
	//cout << b[0][0] << endl;
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		dfs(x - 1, y - 1, i);
		ans[i] = nu[i];
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << b[i][j];
			cout << endl;
		}*/
	}
	for (int i = 0; i < m; i++)
		cout << nu[i] << endl;
	/*cout << x << y << n << m << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout<< a[i][j];*/
	system("pause");
	return 0;
}