#include<iostream>
using namespace std;
int a[22][22];
int b[500][3]; 
int m, n, k,c;
int sum,sum1;
int jl(int a, int a1, int b, int b1)
{
	int x = a - a1, y = b - b1;
	if (x < 0)x = 0 - x;
	if (y < 0)y = 0 - y;
	return x + y;
}
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 0)
			{
				b[c][0] = i;//x
				b[c][1] = j;//y
				b[c][2] = a[i][j];//»¨ÉúÊı
				c++;
			}
			else continue;
		}
	for (int i = 0; i < c; i++)
	{
		int k1=i;
		for (int j = i + 1; j < c; j++)
			if (b[j][2] > b[k1][2])
				k1 = j;
		int temp = b[k1][0], temp1 = b[k1][1], temp2 = b[k1][2];
		b[k1][0] = b[i][0]; b[k1][1] = b[i][1]; b[k1][2] = b[i][2];
		b[i][0] = temp, b[i][1] = temp1, b[i][2] = temp2;
	}
	/*for (int i = 0; i < c; i++)
		cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;*/
	int i=0;
	sum += b[i][0] + 1;
	while (sum + b[i][0]+2<= k)
	{
		sum++;
		sum1 += b[i][2];
		i++;
		sum += jl(b[i][0], b[i - 1][0],b[i][1],b[i-1][1]);
	}
	cout << sum1 << endl;
	system("pause");
	return 0;
}
