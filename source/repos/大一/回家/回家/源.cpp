#include<iostream>
using namespace std;
int n, m;
int minbu=120,bu = 0;
int hp = 6;
int a[11][11];
int k[4][2] = { 0,1,1,0,0,-1,-1,0 };
int dx,dy,chux,chuy,mox,moy;
inline int digui(int x, int y,int hp)
{
	if (hp==0 || bu > n*m||bu>minbu)return 0;
	else 
		if (a[x][y] == 3)
		{
			//cout << bu << endl;
			minbu = bu;
			return 0;
		}
	if (a[dx][dy] == 4)
		hp = 6;
	else
		hp--;
	for (int i = 0; i < 4; i++)
	{
		dx= x + k[i][0];
		dy = y + k[i][1];
		if (dx<0 || dy<0 || dx>n - 1 || dy>m - 1||a[dx][dy]==0)
			continue;
		//cout << "(" << x << "," << y << ")" << bu << endl;
		bu++;
		digui(dx, dy,hp);
		bu--;
	}
	//cout << minbu << endl;
	return 0;
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2)
			{
				chux = i; chuy = j;
			}
			else
				if (a[i][j] == 3)
				{
					mox = i; moy= j;
				}
		}
	dx = chux; dy = chuy;
	//cout << dx << dy << endl;
	digui(dx, dy,6);
	if (minbu >= n * m)
		cout << -1 << endl;
	else
		cout << minbu << endl;
	system("pause");
	return 0;
}