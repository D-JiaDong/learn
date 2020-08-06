#include<iostream>
using namespace std;
int map[10][10];
int visi[10][10];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int N, M, T;
int coun;
void dfs(int x,int y)
{
	if (x < 0 || y<0 || x >= N || y>=M || visi[x][y] == 1||map[x][y]==1)
		return;
	if (map[x][y] == 3)
	{
		coun++;
		return;
	}
	visi[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dir[i][0], y + dir[i][1]);
	}
	visi[x][y] = 0;
}
int main()
{
	cin >> N >> M >> T;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	map[x1-1][y1-1] = 2; map[x2-1][y2-1] = 3;
	int x3, y3;
	while (T--)
	{
		cin >> x3 >> y3;
		map[x3-1][y3-1] = 1;
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}*/
	dfs(x1-1, y1-1);
	cout << coun << endl;
	system("pause");
	return 0;
}