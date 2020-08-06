#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char Word[21][20] = {"a","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve",
"thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty" };
char word[6][20];
int num[6]; int N;
int main() 
{
	int i = 0; int j = 0;
	char c = getchar();
	while (c != '.')
	{
		if (c == ' ')
		{
			i++; j = 0;
			c = getchar();
			continue;
		}
		word[i][j++] = c;
		c = getchar();
	}
	for (int i = 0; i < 6; i++)
	{
		if (strlen(word[i])==1&&(word[i][0] == Word[0][0] || word[i][0] == Word[0][0] - 32))
		{
			num[N++] = 1;
			continue;
		}
		for (int j = 1; j < 21; j++)
		{
			int n = 0;
			for (int k = 0; k < (strlen(Word[j])); k++)
			{
				if (!(word[i][k] == Word[j][k] ||word[i][k] == Word[j][k] - 32))
				{
					n = 1; break;
				}
			}
			if (n == 0)
			{
				num[N++] = j * j % 100;
				break;
			}
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < N; j++)
		{
			int x = num[k], y = num[j];
			if (num[k] >= 10 && num[j] >= 10)
				x = num[k] / 10, y = num[j] / 10;
			if (x > y)
				k = j;
		}
		int temp = num[k];
		num[k] = num[i];
		num[i] = temp;
	}
	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	int m = 0; int count = 0;
	while (m < N)
		if (num[m] == 0)
		{
			m++;
			continue;
		}
		else
			if (num[m]<10&&count==0) {
				cout << num[m];
				count++;
				m++;
			}
			else
			{
				if (num[m] < 10)
					cout << 0 << num[m];
				else
					cout << num[m];
				m++;
			}
	system("pause");
	return 0;
}