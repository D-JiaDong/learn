#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
char c[100];
int zf = 1;
int qh = 1;
double csx[20], fc[20];
char wzs;
int x, y;
int main()
{
	int k = 0;
	int C = getchar();
	while (1)
	{
		if (C >= 97 && C <= 122)
			wzs = C;
		c[k++] = C;
		C = getchar();
		if (C == '\n')
			break;
	}
	int i = 0;
	while (i < k)
	{
		if (c[i] == '=')
		{
			qh = -1;
			i++;
			continue;
		}
		if (c[i] == '-')
		{
			zf = -1;
			i++;
			continue;
		}
		if (c[i] >= 97 && c[i] <= 122)
		{
			fc[x++] = qh * zf * 1;
			i++;
			continue;
		}
		if (c[i] >= 48 && c[i] <= 57)
		{
			int sum = 0;
			for (int j = i;; j++)
			{
				if (c[j] >= 48 && c[j] <= 57)
					sum = sum * 10 + (c[j] - 48);
				else
				{
					if (c[j] >= 97 && c[j] <= 122)
					{
						i = j;
						fc[x++] = qh * zf*sum;
					}
					else
					{
						csx[y++] = qh * zf*sum;
						i = j-1;
					}
					break;
				}
			}
		}
		i++;
		zf = 1;
	}
	double chang = 0, feichang = 0, res;
	for (int i = 0; i < y; i++)
		chang += csx[i];
	for (int i = 0; i < x; i++)
		feichang += fc[i];
	/*res = (0 - chang) / feichang;
	if (chang == 0)
		res = 0.0;*/
	cout << wzs << '=' << fixed << setprecision(3) << (0 - chang) / feichang << endl;
	system("pause");		
	return 0;
}