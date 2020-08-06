#include<iostream>
using namespace std;
int can[30][30][30];
long long int x, y, z;
long long int inp[1000000][3];
int w(long long int x, long long int y, long long int z)
{
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;
	else
	{
		if (x > 20 || y > 20 || z > 20)
		{
			if (can[20][20][20] != 0)
				return can[20][20][20];
			else
			{
				can[20][20][20] = w(20, 20, 20);
				return can[20][20][20];
			}
		}
		else
		{
			if (x < y&&y < z)
			{
				if (can[x][y][z] != 0)
					return can[x][y][z];
				else
				{
					can[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
					return can[x][y][z];
				}
			}
			else
			{
				if (can[x][y][z] != 0)
					return can[x][y][z];
				else
				{
					can[x][y][z] = w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1)-w(x-1, y-1, z-1);
					return can[x][y][z];
				}
			}
		}
	}
}
int main()
{
	int i;
	for(i=0;;i++)
	{
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1)
			break;
		inp[i][0] = x; inp[i][1] = y; inp[i][2] = z;
	}
	for (int j = 0; j < i; j++)
		cout << "w(" << inp[j][0] << ", " << inp[j][1] << ", " << inp[j][2] << ") = " << w(inp[j][0], inp[j][1], inp[j][2]) << endl;
	system("pause");
	return 0;
}