#include<iostream>
using namespace std;
int row[27];       //ÿһ�ж�Ӧ��λ��
bool bo[27];       //�ж������Ƿ�ʹ�ù�
int wo[27];
int n;             //������
char map[3][26];   //�ַ�������
int map1[3][26];   //��ǵ��ʵ�һ�γ��ֵ�λ��
int co[27];
bool en;           //�������ƥ�������ѭ��
void dfs(int x, int y)
{
	if (x < 0 || x >= 3 || y < 0 || y >= n || en)
		return;
	int c = map[x][y] - 65;
	//��ǰ��ĸδ����ֵʱ
	if (map1[x][y] == 1)
	{
		if (x == 2)
		{
			int a1 = wo[map[0][y] - 65], a2 = wo[map[1][y] - 65];
			int yu = (a1 + a2 + row[y + 1]) % n;
			row[y] = (a1 + a2 + row[y + 1]) / n;
			if (!bo[yu])
			{
				bo[yu] = true;
				wo[c] = yu;
				dfs(0, y - 1);
				bo[yu] = false;
			}
		}
		else
			for (int i = n - 1; i >= 0; i--)
			{
				if (en)
					return;
				//�������iδ��ʹ��
				if (!bo[i])
				{
					bo[i] = true;
					wo[c] = i;
					dfs(x + 1, y);
					bo[i] = false;
				}
			}
	}
	else
	{
		if (x == 2)
		{
			int a1 = wo[map[0][y] - 65], a2 = wo[map[1][y] - 65];
			int yu = (a1 + a2 + row[y + 1]) % n;
			row[y] = (a1 + a2 + row[y + 1]) / n;
			if (yu == wo[c])
				dfs(0, y - 1);
		}
		else
			dfs(x + 1, y);
	}
	if (x == 2 && y == 0 && wo[c] != -1)
	{
		en = true;
		for (int i = 0; i < n; i++)
			cout << wo[i] << ' ';
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int j = n - 1; j >= 0; j--)
		for (int i = 0; i < 3; i++)
		{
			if (co[map[i][j] - 65] == 0)
				map1[i][j] = 1;
			co[map[i][j] - 65] = 1;
		}
	dfs(0, n - 1);
	return 0;
}