#include<iostream>
using namespace std;
char dc[11];
char wz[1000001];
int qs=-1;
int main()
{
	int count=0;
	int k = 0;//ÎÄÕÂ³¤¶È
	gets_s(dc);
	gets_s(wz);
	k = strlen(wz);
	int m = -1,n =0;
	int i = 0;
	while(i<k)
	{
		if ((wz[i] >= 65 && wz[i] <= 90) || (wz[i] >= 97 && wz[i] <= 122))
		{
			i++;
			n++;
		}
		else
		{
			int t = 1;
			if(strlen(dc)==n-m-1)
				for (int j = m + 1; j <n; j++)
				{
					if (wz[j] == dc[j - m - 1] || wz[j] == dc[j - m - 1] + 32 || wz[j] + 32 == dc[j - m - 1])
						continue;
					else
					{
						t = 0;
						break;
					}
				}
			else
			{
				t = 0;
			}
			if (t == 1)
			{
				count++;
				if (count == 1)
					qs = m+1;

			}
			n++;
			m = n-1;
			i = n;
		}
	}
	if (count == 0)
		cout << -1 << endl;
	else
		cout << count << " " << qs << endl;
	system("pause");
	return 0;

}