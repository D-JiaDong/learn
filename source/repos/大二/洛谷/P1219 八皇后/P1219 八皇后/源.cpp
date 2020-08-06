#include<iostream>
using namespace std;
int visit[15][2];           //判断当前行列是否有棋子
int bhh[15];                //存棋子坐标
int k[50][2];               //判断当前棋子所处对角线是否有棋子
int n;                     //棋盘大小
int cou;                   //当前所放棋子个数
int coun;                 //解的总数
void dfs(int x,int y)
{
	if (visit[x][0] == 1 || visit[y][1] == 1 || k[y - (-1)*x + n][0] == 1 || k[y - x + n][1] == 1)//列行对角线已有棋子 return
		return;
	cou++;
	visit[x][0] = 1; visit[y][1] = 1;               //标记当前棋子所在行列
	k[y - (-1)*x + n][0] = 1; k[y - x + n][1] = 1;    //标记当前棋子所在对角线
	bhh[x-1] = y;                                    //标记该棋子坐标                          
	if (cou == n)                                    //如果棋子个数达到规定数目
	{
		coun++;                                     //解的总数加一
		if (coun < 4)								//输出前三个
		{
			for (int i = 0; i < n; i++)
				cout << bhh[i] << ' ';
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++)                //搜索下一行
	{                            
		if (i + 1 >= y - 1 && i + 1 <= y + 1)  //排除当前位置的下方 左下方 右下方
			continue;
		dfs(x + 1, i + 1);                     //深搜
	}
	//回溯
	visit[x][0] = 0; visit[y][1] = 0;          
	k[y - (-1)*x+n][0] = 0; k[y - x+n][1] = 0;
	cou--;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)  //对第一行的每一列深搜
		dfs(1, i + 1);
	cout << coun << endl;
	system("pause");
	return 0;
}