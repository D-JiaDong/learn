#include<iostream>
#include<queue>
using namespace std;
struct zb {
	int x;
	int y;
	char d;
	int step;//一共的步数
};
queue<zb> que;
int N, M;
int sta_x, sta_y, end_x, end_y;
char dir;
int Dir[4][2] = { 1,0,0,1,-1,0,0,-1 };//下，右，上，左
int _map[53][53];
int map[53][53];
int visit[53][53][4];

//ans函数 由已知直线求出最短步数
int ans(int n)
{
	int anser = 0;
	int a = n / 3;
	int yu = n % 3;
	anser += a;
	a = yu / 2;
	yu = yu % 2;
	anser += a;
	anser += yu;
	return anser;
}

//判断该位置是否经过
bool bo(zb a)
{
	int c;    //当前位置状态 四个方向
	if (a.d == 'S')c = 0;
	if (a.d == 'N')c = 1;
	if (a.d == 'W')c = 2;
	if (a.d == 'E')c = 3;
	if (map[a.x][a.y] == 1 || visit[a.x][a.y][c] == 1 || a.x <= 0 || a.y <= 0 || a.x >= N || a.y >= M)
		return false;
	return true;
}
//广搜
void bfs() {
	while (!que.empty())
	{
		//得到队头结点信息
		int x0 = que.front().x;
		int y0 = que.front().y;
		char d0 = que.front().d;
		int step = que.front().step;

		//标记经过的点
		int a = -1;
		if (d0 == 'S')a = 0;
		if (d0 == 'N')a = 1;
		if (d0 == 'W')a = 2;
		if (d0 == 'E')a = 3;
		visit[x0][y0][a] = 1;
		

		//到达 输出结果并退出
		if (x0 == end_x && y0 == end_y)
		{
			cout << step;
			return;
		}

		//四种方向情况  入队操作
		if (d0 == 'S')
		{
			//方向一致 三种步数
			zb dq1;
			dq1.x = x0 + 1; dq1.y = y0; dq1.step = step + 1; dq1.d = 'S';
			if (bo(dq1))
				que.push(dq1);
			zb dq2;
			dq2.x = x0 + 2; dq2.y = y0; dq2.step = step + 1; dq2.d = 'S';
			if (bo(dq1) && bo(dq2))
				que.push(dq2);
			zb dq3;
			dq3.x = x0 + 3; dq3.y = y0; dq3.step = step + 1; dq3.d = 'S';
			if (bo(dq1) && bo(dq2) && bo(dq3))
				que.push(dq3);

			//方向不同 两种转向
			zb dq;
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'E';
			if (bo(dq))
				que.push(dq);
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'W';
			if (bo(dq))
				que.push(dq);
		}
		if (d0 == 'N')
		{
			zb dq1;
			dq1.x = x0 - 1; dq1.y = y0; dq1.step = step + 1; dq1.d = 'N';
			if (bo(dq1))
				que.push(dq1);
			zb dq2;
			dq2.x = x0 - 2; dq2.y = y0; dq2.step = step + 1; dq2.d = 'N';
			if (bo(dq1) && bo(dq2))
				que.push(dq2);
			zb dq3;
			dq3.x = x0 - 3; dq3.y = y0; dq3.step = step + 1; dq3.d = 'N';
			if (bo(dq1) && bo(dq2) && bo(dq3))
				que.push(dq3);
			zb dq;
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'E';
			if (bo(dq))
				que.push(dq);
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'W';
			if (bo(dq))
				que.push(dq);
		}
		if (d0 == 'W')
		{
			zb dq1;
			dq1.x = x0; dq1.y = y0 - 1; dq1.step = step + 1; dq1.d = 'W';
			if (bo(dq1))
				que.push(dq1);
			zb dq2;
			dq2.x = x0; dq2.y = y0 - 2; dq2.step = step + 1; dq2.d = 'W';
			if (bo(dq1) && bo(dq2))
				que.push(dq2);
			zb dq3;
			dq3.x = x0; dq3.y = y0 - 3; dq3.step = step + 1; dq3.d = 'W';
			if (bo(dq1) && bo(dq2) && bo(dq3))
				que.push(dq3);
			zb dq;
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'N';
			if (bo(dq))
				que.push(dq);
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'S';
			if (bo(dq))
				que.push(dq);
		}
		if (d0 == 'E')
		{
			zb dq1;
			dq1.x = x0; dq1.y = y0 + 1; dq1.step = step + 1; dq1.d = 'E';
			if (bo(dq1))
				que.push(dq1);
			zb dq2;
			dq2.x = x0; dq2.y = y0 + 2; dq2.step = step + 1; dq2.d = 'E';
			if (bo(dq1) && bo(dq2))
				que.push(dq2);
			zb dq3;
			dq3.x = x0; dq3.y = y0 + 3; dq3.step = step + 1; dq3.d = 'E';
			if (bo(dq1) && bo(dq2) && bo(dq3))
				que.push(dq3);
			zb dq;
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'N';
			if (bo(dq))
				que.push(dq);
			dq.x = x0; dq.y = y0; dq.step = step + 1; dq.d = 'S';
			if (bo(dq))
				que.push(dq);
		}
		que.pop();
	}
	cout << -1 << endl;
}
int main()
{   //输入
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> _map[i][j];
	cin >> sta_x >> sta_y >> end_x >> end_y;
	cin >> dir;
	//重新构图  初始化map数组
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (_map[i][j] == 1)
			{
				map[i][j] = 1;
				map[i][j + 1] = 1;
				map[i + 1][j] = 1;
				map[i + 1][j + 1] = 1;
			}
		}

	//完善初始位置结点 并入队
	zb st;
	st.x = sta_x; st.y = sta_y;
	st.d = dir;
	st.step = 0;
	que.push(st);

	//广搜
	bfs();
	system("pause");
	return 0;
}