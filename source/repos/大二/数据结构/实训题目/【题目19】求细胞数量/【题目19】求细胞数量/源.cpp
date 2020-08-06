#include<iostream>
using namespace std;
int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
char map[102][102];
int m, n;
int coun;
void dfs(int x,int y,int step) {
	//�����߽�����Ƿ�ϸ�� return;
	if (x < 0 || x >= m || y < 0 || y >= n||map[x][y]=='0')       
		return;
	//һ��ϸ������һ��
	if (step == 1)
		coun++;
	//��������б���ǵ�ϸ��Ⱥ���Ϊ��ϸ�� 
	map[x][y] = '0';
	for (int i = 0; i < 4; i++)
		dfs(x + dir[i][0], y + dir[i][1], step + 1);
}
int main() {
	//��������
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	//��ÿ���������������
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			dfs(i, j, 1);
	cout << coun << endl;
	system("pause");
	return 0;
}