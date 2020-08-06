#include<iostream>
using namespace std;
int main()
{
	int cishu = 0, er;
	int M, N, e[1001], nei[101];
	cin >> M >> N;
	int m = M;
	for (int i = 0; i < N; i++)
		cin >> e[i];
	for (int i = 0; i < M; i++)
		nei[i] = -1;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		for (int j = 0; j < i; j++)
		{
			if (e[i] == e[j])
			{
				n++;
			}
		}
		if (n == 0)
			for (int k = 0; k < M; k++)
			{
				if (nei[k] == -1)
				{
					nei[k] = e[i];
					er = i;
					break;
				}
			}
	}
	for (int i = er + 1; i < N; i++)
	{
		int n = 0;
		for (int j = 0; j < M; j++)
		{

			if (e[i] == nei[j])
			{
				n++;
				break;
			}
		}
		if (n == 0)
		{
			for (int k = 0; k < M - 1; k++)
				nei[k] = nei[k + 1];
			nei[M-1] = e[i];
			m++;
		}
	}
	cout << m << endl;
	system("pause");
	return 0;
}