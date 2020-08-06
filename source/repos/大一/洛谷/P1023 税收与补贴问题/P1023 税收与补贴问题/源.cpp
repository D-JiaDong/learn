#include<iostream>
using namespace std;
int a[100004][3];
int zfj;
int dj;
int n=-1;
int b = 0;
int main()
{
	cin >> zfj;
	int max1=1;
	int i = 0;
	cin >> a[0][0] >> a[0][1];
	do
	{
	  i++;
	  cin >> a[i][0] >> a[i][1];
	  max1 = i;
	  int cha = a[i][0] - a[i - 1][0];
	  if (cha >1)
	  {
		  int x = (a[i - 1][1] - a[i][1]) / (a[i][0] - a[i - 1][0]);
		  for ( int k = 0; k <cha; k++)
		  {
			  a[i + k][0] = a[i + k - 1][0] + 1; a[i + k][1] = a[i + k - 1][1] - x;
			  max1 = i + k;
		  }
	  }
	  i = max1;
	} while (a[i][0] != -1 && a[i][0] != -1);
	int x = a[i-1][0], y = a[i-1][1];
	cin >> dj;
	for (;; i++)
	{
		x++;
		y -= dj;
		if (y<=0)break;
		a[i][0] = x; a[i][1] = y;
	}
	int k = i;
	/*for (int i = 0; i < k; i++)
		cout << a[i][0] << ' ' << a[i][1] << endl;*/
	for (int i = 0; i <= 10000; i++)
	{
		int max[2];
		max[0] = 0; max[1] = -1;
		for (int j = 0; j < k; j++)
		{
			if ((a[j][0] - a[0][0] - i)*a[j][1] >= max[0])
			{
				max[0] = (a[j][0] - a[0][0] - i)*a[j][1];
				max[1] = j;
			}
		}
		if (a[max[1]][0] == zfj)
		{
			n = i;
			break;
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		int max[2];
		max[0] = 0; max[1] = -1;
		for (int j = 0; j < k; j++)
		{
			if ((a[j][0] - a[0][0] +i)*a[j][1] > max[0])
			{
				max[0] = (a[j][0] - a[0][0] +i)*a[j][1];
				max[1] = j;
			}
		}
		if ((n == -1 && a[max[1]][0] == zfj) || (n != -1 && a[max[1]][0] == zfj && i < n))
		{
			n = i; b = 1;
			cout << i << endl;
			break;
		}
	}
	if (b == 0 && n != -1)
		cout << "-" << n<<endl;
	if (n == -1)
		cout << "NO SOLUTION" << endl;
	system("pause");
	return 0;
}
