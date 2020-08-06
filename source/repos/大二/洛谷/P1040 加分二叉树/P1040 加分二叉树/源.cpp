//#include<iostream>
//using namespace std;
//int n;
//int node[33][33];  //用来存放前序i-j形成的数的根
//int jf[33];     //存放结点分数
//int dp[33][33]; 
//int dfs(int L,int R)
//{
//	if (dp[L][R] > 0)
//		return dp[L][R];
//	//L>R这个时候该子树为空 返回值为1 
//	if (L > R)
//		return 1;
//	//叶子结点 返回本身分数
//	if (L == R)
//	{
//		node[L][R] = L;
//		return jf[R];
//	}
//	//下边这个过程选择的是从L到R之间的最优的根
//	//这时候L到R之间有多个结点 所以需要遍历取最优 
//	//区间动态规划
//	if (L < R)
//	{
//		for (int i = L; i <= R; i++)
//		{
//			int temp = dfs(L, i - 1)*dfs(i + 1, R) + jf[i];
//			if (temp > dp[L][R])
//			{
//				node[L][R] = i;
//				dp[L][R] = temp;
//			}
//		}
//	}
//	return dp[L][R];
//}
//void prin(int L,int R)
//{
//	if (L > R)
//		return;
//	cout << node[L][R] << ' ';
//	prin(L, node[L][R] - 1);
//	prin(node[L][R] + 1, R);
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> jf[i];
//	dfs(1, n);
//	cout << dp[1][n] << endl;
//	prin(1, n);
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		float a, b;
		cin >> a >> b;
		cout << (a + b)*0.05*0.5;
	}
	system("pause");
	return 0;
}