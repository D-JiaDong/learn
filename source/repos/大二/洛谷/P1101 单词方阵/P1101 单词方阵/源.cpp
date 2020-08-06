#include<iostream>
#include<stack>
using namespace std;
struct coordinate
{
	char c;
	int x; int y;
};
int dir[8][2] = { 1,0, -1,0, 0,1, 0,-1, 1,1, 1,-1, -1,1, -1,-1 };
int word[7] = { 'y','i','z','h','o','n','g' };
coordinate map[102][102];
stack<coordinate> way;
int ans[102][102];
int n;
void dfs(int x,int y,int cou,int Dir)
{
	if (x < 0 || y < 0 || x >= n || y >= n||map[x][y].c!=word[cou])
		return;
	if (cou==6)
	{
		ans[x][y] = 1;
		coordinate w[6];
		int i = 0;
		while (!way.empty())
		{
			w[i].c = way.top().c;
			w[i].x = way.top().x;
			w[i].y = way.top().y;
			ans[way.top().x][way.top().y] = 1;
			way.pop();
			i++;
		}
		for (int j = i-1; j>=0; j--)
			way.push(w[j]);
		return;
	}
	way.push(map[x][y]);
	if (Dir != -1)
		dfs(x + dir[Dir][0], y+dir[Dir][1], cou + 1, Dir);
	else
		for (int i = 0; i < 8; i++)
			dfs(x + dir[i][0], y + dir[i][1], cou + 1,i);
	way.pop();
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j].c;
			map[i][j].x = i; map[i][j].y = j;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (map[i][j].c == word[0])
				dfs(i, j, 0,-1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[i][j] == 1)
				cout << map[i][j].c;
			else
				cout << '*';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}