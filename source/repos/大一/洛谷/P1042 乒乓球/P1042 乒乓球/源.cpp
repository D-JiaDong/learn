#include<iostream>
using namespace std;
char c;
int off;
int x, y;
int a[62600][3];
int main()
{
	int i = 0;
	while(1)
	{
		c = getchar();
		if (c > 90 || c < 65)
			continue;
		else i++;
		if (c == 'E')
		{
			a[i][2] = 1;
			break;
		}
		else if (c == 'W')
			a[i][0] = 1;
		else if (c == 'L')
			a[i][1] = 1;
	}
	int j = 0;
	i = 0;
	while (1)
	{
		x += a[i][0]; y += a[i][1];
		j++;
		if (a[i][2] == 1)
		{
			cout << x << ":" << y << endl;
			x = 0; y = 0;
			break;
		}
		if ((x == 11 && x - y >= 2) || (y==11&&y-x>=2)||((x>11||y>11)&&(x-y>=2||y-x>=2)))
		{
			cout << x << ":" << y << endl;
			x = 0; y = 0;j = 0;
		}
		i++;

	}
	cout << endl;
	j = 0;i = 0;
	while (1)
	{
		x += a[i][0]; y += a[i][1];
		j++;
		if (a[i][2] == 1)
		{
			cout << x << ":" << y << endl;
			break;
		}
		if ((x == 21 && x - y >= 2) || (y == 21 && y - x >= 2) || ((x > 21 || y > 21) && (x - y >= 2 || y - x >= 2)))
		{
			cout << x << ":" << y << endl;
			x = 0; y = 0; j = 0;
		}
		i++;
	}
	system("pause");
	return 0;
}


