//#include<iostream>
//using namespace std;
//int n;
//int node[33][33];  //�������ǰ��i-j�γɵ����ĸ�
//int jf[33];     //��Ž�����
//int dp[33][33]; 
//int dfs(int L,int R)
//{
//	if (dp[L][R] > 0)
//		return dp[L][R];
//	//L>R���ʱ�������Ϊ�� ����ֵΪ1 
//	if (L > R)
//		return 1;
//	//Ҷ�ӽ�� ���ر������
//	if (L == R)
//	{
//		node[L][R] = L;
//		return jf[R];
//	}
//	//�±��������ѡ����Ǵ�L��R֮������ŵĸ�
//	//��ʱ��L��R֮���ж����� ������Ҫ����ȡ���� 
//	//���䶯̬�滮
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