#include<iostream>
using namespace std;
int a[9][2], b[9], c[9],k[9];
int arr[10];
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int j = 0;
	for (int i = 100; i <= 999 * x / z; i++)
	{
		if (i%x!= 0)
			continue;
		a[j][0] = i; b[j] = i/x*y; c[j] = i/x*z;
		k[0] = a[j][0] / 100; a[j][1] = a[j][1];
		k[1] = a[j][0] % 100 / 10;
		k[2] = a[j][0] % 10;
		k[3] = b[j] / 100;
		k[4] = b[j] % 100 / 10;
		k[5] = b[j] % 10;
		k[6] = c[j] / 100;
		k[7] = c[j] % 100 / 10;
		k[8] = c[j] % 10;
		int tui = 0;
		for (int p = 0; p < 9; p++)
		{
			int p2 = 0;
			for (int p1 = 0; p1 < 9; p1++)
			{
				if (k[p] == k[p1] || k[p1] == 0)
					p2++;
				if (p2 >= 2)
					break;
			}
			if (p2 >= 2)
			{
				tui = 1;
				break;
			}
		}
		if (tui == 0)
			j++;
	}
	if (j == 0)
	{
		cout << "No!!!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < j; i++)
	{
		int k = i;
		for (int h = i + 1; h < j; h++)
			if (a[h][1] < a[k][1])
				k = h;
		int temp1 = a[k][0], temp2 = b[k], temp3 = c[k];
		a[k][0] = a[i][0]; b[k] = b[i]; c[k] = c[i];
		a[i][0] = temp1; b[i] = temp2; c[i] = temp3;
		cout << a[i][0] << ' ' << b[i] << ' ' << c[i] << endl;
	}
	system("pause");
	return 0;
}