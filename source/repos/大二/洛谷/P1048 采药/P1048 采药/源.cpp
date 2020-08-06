//#include<iostream>
//using namespace std;
//int f[102][1002];
//int tim[102], value[102];
//int T, M;
//int main()
//{
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//		cin >> tim[i] >> value[i];
//	for (int i = 1; i <=M; i++)
//		for (int j = T; j >= 1; j--)
//			if (j >= tim[i])
//				f[i][j] = (f[i - 1][j] >= f[i - 1][j - tim[i]] + value[i]) ? f[i - 1][j] : f[i - 1][j - tim[i]] + value[i];
//			else
//				f[i][j] = f[i - 1][j];
//	cout << f[M][T] << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
int f[102][1002];
int tim[102], value[102];
int T, M;
int main()
{
	cin >> T >> M;
	for (int i = 1; i <= M; i++)
		cin >> tim[i] >> value[i];
	for (int i = 1; i <= M; i++)
		for (int j = T; j >= 1; j--)
			if (j >= tim[i])
			{
				int max = f[i - 1][j];
				for (int k = j / tim[i]; k > 0; k--)
				{
					
					max = (max >= f[i - 1][j -k*tim[i]] + k*value[i]) ? max: f[i - 1][j -k*tim[i]] + k*value[i];
				}
				f[i][j] = max;
			}
			else
				f[i][j] = f[i - 1][j];
	cout << f[M][T] << endl;
	system("pause");
	return 0;
}