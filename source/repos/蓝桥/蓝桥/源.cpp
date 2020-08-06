//#include<iostream>
//#include<queue>
//#include<stack>
//#include<algorithm>
//#include<iomanip>
//#include<string>
//using namespace std;
//struct student {
//	string sname;
//	int sage;
//	string sxex;
//};
//bool cmp(int a, int b)
//{
//	if (a < b)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	sort(arr, arr + 8);
//	for(int i=0;i<10;i++)
//		cout << arr[i]<<' ';
//	//cout << endl << fixed << setprecision(4) << 3.111111 << endl;
//	cout<< setprecision(3) << 3.111111 << endl;
//	cout << setw(4) << 1;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<stack>
//using namespace std;
//int ans;
//int n,m;
//int s[7];
//bool bo[7][7];
//int dfs(int up,int n) {
//	if (n < 0)
//		return 0;
//	if (n == 0) {
//		ans++;
//		return 0;
//	}
//	for (int i = 1; i < 7; i++)
//		if(!bo[up][s[i]])
//			dfs(i, n - 1);
//	return 0;
//}
//int cheng(int n) {
//	int result=1;
//	for (int i = 0; i < n; i++)
//		result*=4;
//	return result;
//}
//int main()
//{
//	s[1] = 4; s[2] = 5; s[3] = 6; s[4] = 1; s[5] = 2; s[6] = 3;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		bo[x][y] = true;
//		bo[y][x] = true;
//	}
//	for (int i = 1; i <= 6; i++)
//		dfs(i, n - 1);
//	cout << ans * cheng(n) << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<iomanip>
using namespace std;
int d[9][9];//d数组 存放每个顶点到每个顶点的最短距离
int p[9][9];//p数组 存放最短路径
int main(){
	//初始化数组
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++){
			d[i][j] = 0xfffffff;
			p[i][j] = j;
		}
	//向邻接矩阵中写入权值
	{

		d[0][0] = 0; d[0][1] = 1; d[0][2] = 5;
		d[1][0] = 1; d[1][1] = 0; d[1][2] = 3; d[1][3] = 7; d[1][4] = 5;
		d[2][0] = 5; d[2][1] = 3; d[2][2] = 0; d[2][4] = 1; d[2][5] = 7;
		d[3][1] = 7; d[3][3] = 0; d[3][4] = 2; d[3][6] = 3;
		d[4][1] = 5; d[4][2] = 1; d[4][3] = 2; d[4][4] = 0; d[4][5] = 3; d[4][6] = 6; d[4][7] = 9;
		d[5][2] = 7; d[5][4] = 3; d[5][5] = 0; d[5][7] = 5;
		d[6][3] = 3; d[6][4] = 6; d[6][6] = 0; d[6][7] = 2; d[6][8] = 7;
		d[7][4] = 9; d[7][5] = 5; d[7][6] = 2; d[7][7] = 0; d[7][8] = 4;
		d[8][6] = 7; d[8][7] = 4; d[8][8] = 0; 
	}
	//更新存放最短距离的d邻接矩阵  更新存放路径的p数组
	for (int k = 0; k < 9; k++)
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				if (d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}
			}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << setw(4)<< d[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout <<setw(4)<< p[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}