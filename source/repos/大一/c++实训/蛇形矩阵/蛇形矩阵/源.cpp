#include<iostream>
using namespace std;
int a[100][100];
int main()
{
	int n;
	cin >> n;
	a[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		int k = i+1;//初始化第i行第二个要加的数
		for (int j = 0; j < n - i; j++)
		{
			if (j == 0 && i != 0)//如果他是第一列但不是第一行，他就等于上一行的第二个元素减一
				a[i][j] = a[i - 1][j + 1] - 1;
			if (j > 0)//如果他不是第一列，他就等于改行的上一列加k
				a[i][j] = a[i][j - 1] + k;
			cout << i + 1 << "行" << j + 1 << "列" <<"  "<<a[i][j]<< endl;
			k++;//每列结束后k++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			cout << a[i][j]<<" ";
		cout << endl;
	}
	system("pause");
	return 0;
}