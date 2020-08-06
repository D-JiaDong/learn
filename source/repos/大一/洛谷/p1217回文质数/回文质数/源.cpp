#include<iostream>
#include<cmath>
using namespace std;
bool s[100000001];
inline int huiwen(int  a)
{
	int b = a;
	int c = 0;
	int d = 0;
	while (a)
	{
		c = c * 10 + a % 10;
		a = a / 10;
	}
	if (c == b)
		return 1;
	else
		return 0;
}
int main()
{
	int a, b;
	cin >> a >> b;
	if (b > 10000000)
		b = 10000000;
	for (int i = 1; i <= b; i++)
		s[i] = true;
	s[1] = false, s[2] = true;
	for (int i = 2; i <= b; i++)
	{
		if (s[i])
		{
			for (int j = 2 * i; j <= b; j += i)
			{
				s[j] = false;
			}
		}
	}
	if (a % 2 == 0)
		a++;
	for (int i = a; i <= b; i++)
		if (s[i])
			if (huiwen(i) == 1)
				cout << i << endl;
	return 0;
}