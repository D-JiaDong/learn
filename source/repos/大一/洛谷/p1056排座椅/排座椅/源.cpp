#include<iostream>
using namespace std;
int a[2001][2][2];
int H[2001], H1[2001], L[2001], L1[2001];
int main()
{
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				cin >> a[i][j][k];
	for (int i = 0; i < m - 1; i++)
		H[i] = 0;
	for (int i = 0; i < n - 1; i++)
		L[i] = 0;
	//初始化行列
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < d; j++)
			if ((a[j][0][0] == i + 1 && a[j][1][0] == i + 2) || (a[j][0][0] == i + 2 && a[j][1][0] == i + 1))
				H[i]++;
		//cout << i << "tiaohang" << H[i] << endl;
	}
	//每行解决学生对数
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < d; j++)
			if ((a[j][0][1] == i + 1 && a[j][1][1] == i + 2) || (a[j][0][1] == i + 2 && a[j][1][1] == i + 1))
				L[i]++;
		//cout << i << "tiaolie" << L[i] << endl;
	}
	//每列解决学生对数
	for (int i = 0; i < k; i++)
	{
		int max1 = H[0]; int j1 = 0;
		for (int j = 0; j < m - 1; j++)
			if (max1 < H[j])
			{
				max1 = H[j];
				j1 = j;
			}
		//cout << j1+1 << " ";
		H[j1] = -1;
		H1[i] = j1 + 1;
	}
	//行线获取
	//cout << endl;
	for (int i = 0; i < k - 1; i++)
	{
		int c = i;
		for (int j = i + 1; j < k; j++)
			if (H1[c] > H1[j])
				c = j;
		int temp = H1[i];
		H1[i] = H1[c];
		H1[c] = temp;
		//cout << H1[i] << " ";
	}
	//行线排列
	//cout << endl;
	for (int i = 0; i < l; i++)
	{
		int max2 = L[0]; int j2 = 0;
		for (int j = 0; j < n - 1; j++)
			if (max2 < L[j])
			{
				max2 = L[j];
				j2 = j;
			}
		L[j2] = -1;
		L1[i] = j2 + 1;
	}
	//列线获取
	for (int i = 0; i < l - 1; i++)
	{
		int c = i;
		for (int j = i + 1; j < l; j++)
			if (L1[c] > L1[j])
				c = j;
		int temp = L1[i];
		L1[i] = L1[c];
		L1[c] = temp;
	}
	//列线排列
	for (int i = 0; i < k; i++)
		cout << H1[i] << " ";
	//输出行
	cout << endl;
	for (int i = 0; i < l; i++)
		cout << L1[i] << " ";
	//输出列
	cout << endl;
	system("pause");
	return 0;
}