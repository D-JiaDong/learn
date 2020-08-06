#include<iostream>
using namespace std;
int sushu(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return 1;
	return 0;
}
int main()
{
	int a;
	cin >> a;
	for (int i = 2; i < a; i++)
		for (int j = i; j < a; j++)
		{
			int k = a - i - j;
			if (sushu(i) + sushu(j) + sushu(k) == 0&&k!=0)
			{
				cout << i << ' ' << j << ' ' << k << endl;
				system("pause");
				return 0;
			}
		}
}