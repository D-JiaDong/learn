#include <iostream>
#include <algorithm>
using namespace std;
int i, g[10000000], a[10000000], len, k[10000000], zen;
const int inf = 0x7f7f7f7f;
int main()
{
	g[0] = -inf;
	k[0] = inf;
	while (cin >> a[++i])
	{
		if (a[i] <= k[zen]) { zen++; k[zen] = a[i]; }
		else
		{
			int h = 0, d = zen, mid;
			while (h < d)
			{
				mid = (h + d) >> 1;
				if (k[mid] >= a[i])
					h = mid + 1;
				else
					d = mid;
			}//������k�������ҵ�һ��С��a[i]����
			k[h] = max(k[h], a[i]);//���бȽϣ�̰��˼��
		}
		if (a[i] > g[len])
		{
			len++;
			g[len] = a[i];
			continue;
		}
		int x = 0, y = len, mid;
		while (x < y)
		{
			mid = (x + y) >> 1;
			if (g[mid] >= a[i])
				y = mid;
			else
				x = mid + 1;
		}//������g�������ҵ�һ�����ڵ���a[i]����
		g[x] = min(g[x], a[i]);//���бȽϣ�̰��˼��
	}
	cout << zen << endl << len;
	system("pause");
	return 0;
}