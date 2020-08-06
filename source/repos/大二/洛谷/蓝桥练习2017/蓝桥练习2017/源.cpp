//#include<iostream>
//using namespace std;
//int by[32][8];
//int zj[32];
//void prin(int a,int k)
//{
//	int i = 8;
//	while (i--)
//	{
//		by[k][i] = a % 2;
//		a = a / 2;
//		if (a == 0)
//			break;
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		if (by[k][i] == 0)
//			cout << ' ';
//		else
//			cout << '-';
//	}
//}
//int main()
//{
//	for (int i = 0; i < 32; i++)
//	{
//		cin >> zj[i];
//		prin(zj[i],i);
//		if(i%2!=0)
//		cout << endl;
//	}
//	cout << endl;
//	cout << 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int x, y;
//	cin>>x>>y;
//	if (x == 0 && y == 0)
//		cout << 0 << endl;
//	else
//	{
//		int a, b, a1, b1;
//		if (x < 0)
//			a = 0 - x;
//		else
//			a = x;
//		if (y < 0)
//			b = 0 - y;
//		else
//			b = y;
//		a1 = 0 - a; b1 = 0 - b;
//		int c = a > b ? a : b;
//		int  c1 = 0 - c;
//		int bu=0;
//		int i = c;
//		while (--i)
//		{
//			bu += (i * 2) * 4;
//		}
//		bu++;
//		if (x == c1 && y >= c1 + 1 && y <= c)
//		{
//			cout << bu + y - (c1 + 1);
//			return 0;
//		}
//		if (y == c && x >= c1 && x <= c)
//		{
//			cout << bu + 2 * c - 1 + x - c1;
//			system("pause");
//			return 0;
//		}
//		if (x == c && y >= c1 && y <= c)
//		{
//			cout << bu + 4 * c - 1 + c - y;
//			system("pause");
//			return 0;
//		}
//		if (y == c1 && x >= c1 && x <= c)
//		{
//			cout << bu + 6 * c - 1 + c - x;
//			system("pause");
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//struct tie
//{
//	int ts;
//	int id;
//};
//tie t[1002];
//int idd[1000000];
//int n, d, k;
//bool cmp(tie a,tie b)
//{
//	if (a.id == b.id)
//		return a.ts < b.ts;
//	else
//		return a.id < b.id;
//}
//int main()
//{
//	cin >> n >> d >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t[i].ts >> t[i].id;
//	}
//	sort(t, t + n,cmp);
//	for (int i = 0; i < n; i++)
//	{
//		cout << t[i].id << ' ' << t[i].ts << endl;
//	}
//	int i = -1;
//	while(i<n)
//	{
//		i++;
//		int sum = 0;
//		//cout << i << endl;
//		for (int j = i; j < n; j++)
//		{
//			if (t[j].id == t[i].id)
//			{
//				if (t[i].ts + d > t[j].ts)
//				{
//					sum ++;
//					if (sum >= k)
//					{
//						if (idd[t[j].id] == 0)
//						{
//							cout << t[i].id;
//							idd[t[j].id] = 1;
//						}
//						break;
//					}
//				}
//				else
//				{
//					break;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<stack>
using namespace std;
char map0[1002][1002];
int map1[1002][1002];
int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
int n;
int sum;
bool bo(int x,int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dir[i][0] < 0 || x + dir[i][0] >= n || y + dir[i][1] < 0 || y + dir[i][1] >= n)
			continue;
		if (map0[x + dir[i][0]][y + dir[i][1]]== '.')
			return true;
	}
	return false;
}
void dfs(int x,int y,int k)
{
	if (x < 0 || x >= n || y < 0 || y >= n||map1[x][y]==0)
		return;
	if (k != 1)
		map1[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dir[i][0], y + dir[i][1],k+1);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map0[i][j];
			if (map0[i][j] == '#')
				map1[i][j] = 1;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map0[i][j] == '#')
			{
				if (bo(i, j))
				{
					map1[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(i, j,1);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map1[i][j] == 1)
				sum++;
	cout << sum << endl;
	system("pause");
	return 0;
}
