//01背包
//#include<iostream>
//using namespace std;
//int N, V;
//int v[1002], w[1002];
//int dp[1002];
//int main()
//{
//	cin >> N >> V;
//	for (int i = 1; i <= N; i++) {
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = V; j >= v[i]; j--)
//			dp[j] = (dp[j] >= dp[j - v[i]] + w[i]) ? dp[j] : dp[j - v[i]] + w[i];
//	}
//	cout << dp[V] << endl;
//	system("pause");
//	return 0;
//}

//完全背包
//#include<iostream>
//using namespace std;
//int N, V;
//int v[1002], w[1002];
//int dp[1002];
//int main()
//{
//	cin >> N >> V;
//	for (int i = 1; i <= N; i++) {
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = v[i]; j<=V; j++)
//			dp[j] = (dp[j] >= dp[j - v[i]] + w[i]) ? dp[j] : dp[j - v[i]] + w[i];
//	}
//	cout << dp[V] << endl;
//	system("pause");
//	return 0;
//}

//多重背包
//#include<iostream>
//using namespace std;
//int N, V;
//int v[1002], w[1002], s[1002];
//int dp[1002];
//int main()
//{
//	cin >> N >> V;
//	for (int i = 1; i <= N; i++) {
//		cin >> v[i] >> w[i]>>s[i];
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = V; j>=1; j--)
//			for(int k=1;k<=s[i]&&k*v[i]<=j;k++)
//			dp[j] = (dp[j] >= dp[j - k*v[i]] +k*w[i]) ? dp[j] : dp[j - k*v[i]] + k*w[i];
//	}
//	cout << dp[V] << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
struct goods{
	int g_v;
	int g_w;

};
vector<goods> good;
int N, V;
int v[1002], w[1002], s[1002];
int dp[1002];

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> v[i] >> w[i] >> s[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k < s[i]; k *= 2) {
			s[i] -= k;
			good.push_back({ k*v[i],k + w[i] });
		}
		if (s[i] > 0)
			good.push_back({ s[i]*v[i],s[i]*w[i] });
	}
	for (vector<goods>::iterator it = good.begin(); it != good.end(); it++)
		for (int j = V; j >= 1; j--)
			dp[j] = (dp[j] > dp[j - it->g_v] + it->g_w) ? dp[j] : dp[j - it->g_v] + it->g_w;
	cout << dp[V] << endl;
	system("pause");
	return 0;
}
