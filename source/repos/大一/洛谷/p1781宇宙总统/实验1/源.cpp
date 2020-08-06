#include<iostream>
#define M 200
using namespace std;
class P
{
public:
	char a[M];
};
int weishu(char a[])
{
	int n = 0;
	for (int i = 0; i < M; i++)
		if (a[i] != 0)
			n++;
		else
			break;
	return n;
}
int main()
{
	P b[20];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i].a;
	int max = 0;
	for (int i = 1; i < n; i++)
		if (weishu(b[0].a) < weishu(b[i].a))
		{
			max = i;
			for (int j = 0; j < M; j++)
				b[0].a[j] = b[i].a[j];
		}
		else if (weishu(b[0].a) == weishu(b[i].a))
		{
			for (int j = 0; j < M; j++)
				if (b[0].a[j] < b[i].a[j])
				{
					max = i;
					for (int k = 0; k < M; k++)
						b[0].a[k] = b[i].a[k];
				}
				else if (b[0].a[j] == b[i].a[j])
					continue;
				else break;
		}
	cout << max + 1 << endl;
	cout << b[0].a << endl;
	system("pause");
	return 0;
}