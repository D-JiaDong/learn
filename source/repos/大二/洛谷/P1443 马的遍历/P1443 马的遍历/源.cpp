#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
struct chb {

	int x; int y;
};
int c[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,-2,1,-2,-1,2,1,2 };
int che[402][402];
int m, n;
queue<chb>h;
bool r(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n || che[x][y] != -1)
		return false;
	return true;
}
void bfs(int x,int y)
{
	chb ne;
	ne.x = x; ne.y = y; che[x][y] = 0;
	h.push(ne);
	while (!h.empty())
	{
		for (int i = 0; i < 8; i++)
		{
			ne.x = h.front().x + c[i][0];
			ne.y = h.front().y + c[i][1];
			if (r(ne.x, ne.y))
			{
				h.push(ne);
				//cout << che[h.front().x][h.front().y] + 1 << endl;
				che[ne.x][ne.y] = che[h.front().x][h.front().y] + 1;
			}
		}
		h.pop();
	}
}
int main()
{
	int x, y;
	cin >> m >> n >> x >> y;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			che[i][j] = -1;
	bfs(x - 1, y - 1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4)<<left<<che[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
