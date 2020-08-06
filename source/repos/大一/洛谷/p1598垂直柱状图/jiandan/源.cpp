#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[26];//每个字母最大出现次数
char b[404][26];//*ju矩阵
char str[101];//每一行字母
int c[404];
int main()
{
	for (int i = 0; i < 26; i++)
	{
		a[i] = 0;
		for (int j = 0; j < 26; j++)
			b[i][j] = ' ';
	}
	//初始化数组a,b.
	int max0=0;
	for (int i = 0; i < 4; i++)
	{
		gets_s(str);
		int n = strlen(str);
		for (int j = 0; j < n; j++)
			if (str[j] >= 65 && str[i] <= 90)
				a[str[j] - 65]++;
	}
	//读取数据
	for (int i = 0; i < 26; i++)
	{
		if (a[i] > max0)
			max0 = a[i];
	}
	//求出所有字母最大出现次数
	for (int j = 0; j < 26; j++)
		for (int k = max0-1; k >=max0-a[j]; k--)
			b[k][j] = '*';
	//更改*矩阵
	//最后一行赋字母
	for (int i = 0; i < max0; i++)
	{
		for (int j = 0; j < 25; j++)
			cout << b[i][j] << ' ' ;
		cout << b[i][25];
		cout << endl;
	}
	int dl = 65;
	for (int i = 0; i < 25; i++)
	{
		b[max0][i] = dl++;
		cout << b[max0][i] << " ";
	}
	cout << "Z" << endl;
	//输出
	system("pause");
	return 0;
}