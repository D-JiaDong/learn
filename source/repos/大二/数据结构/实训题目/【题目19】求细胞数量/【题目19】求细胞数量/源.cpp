#include<iostream>
using namespace std;
int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
char map[102][102];
int m, n;
int coun;
void dfs(int x,int y,int step) {
	//超过边界或者是非细胞 return;
	if (x < 0 || x >= m || y < 0 || y >= n||map[x][y]=='0')       
		return;
	//一个细胞计数一次
	if (step == 1)
		coun++;
	//如果四周有被标记的细胞群则归为该细胞 
	map[x][y] = '0';
	for (int i = 0; i < 4; i++)
		dfs(x + dir[i][0], y + dir[i][1], step + 1);
}
int main() {
	//输入数据
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	//对每个点深度优先搜索
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			dfs(i, j, 1);
	cout << coun << endl;
	system("pause");
	return 0;
}