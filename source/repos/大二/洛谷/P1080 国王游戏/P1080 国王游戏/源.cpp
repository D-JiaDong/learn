#include<iostream>
#include<algorithm>
using namespace std;
class  Hands {
public:
	int L;
	int R;
	int LF[8];
	int RF[8];
	void lr()
	{
		int i = 1, j = 1;
		int l = L, r = R;
		while (l != 0)
		{
			LF[i++] = l % 10;
			l = l / 10;
		}
		LF[0] = i;
		while (r != 0)
		{
			RF[j++] = r % 10;
			r = r / 10;
		}
		RF[0] = j;
	}
};
long long int cheng[1006];
Hands king;
Hands government[1004];
int n;
long long int min0 = -1;
int cj[2010];
int cj0[2010];
int *gj(Hands b)
{
	//cout << "................................." << endl;
	int K = 0;
	for (int i = 1; i < b.LF[0]; i++)
	{
		for (int j = 1; j < cj[0]; j++)
		{
			int as = cj[j] * b.LF[i];
			cj0[i + j - 1] += as % 10;
			if (as / 10 != 0)
			{
				cj0[i + j] += as / 10;
				K = i + j+1;
			}
			else
				K = i + j;
		}
	}
	int k = 1; long long int sum = 0;
	while (k != K)
	{
		cj[k] = cj0[k];
		cj0[k] = 0;
		//cout << cj[k] << ' ';
		k++;
	}
	cj[0] = k;
	for (int i = k - 1; i > 0; i--)
	{
		sum = sum * 10 + cj[i];
	}
	//	cout << "................................." << endl;
	int cj1[2010];
	cj1[0] = cj[0];
	cout << '*' << cj1[0] << endl;
	for (int i = 1; i <k; i++)
	{
		cj1[i] = cj[k-i];
		cout <<"&&"<< cj1[i];
	}
	cout << endl;
	return cj;
}
int *gj1(int cj1[], Hands a)
{
	cout << cj1[0] << cj[1]<<endl;
	int c[2010];
	long long int x = 0;
	for (int i = 1;i < cj1[0]; i++)
	{
		c[i] = (x * 10 + cj1[i])/a.R;
		x = (x * 10 + cj1[i]) % a.R;
		cout << c[i] <<endl;
		c[0] = i++;
	}
	int j = 0;
	while (c[j+1] == 0)
	{
		j++;
	}
	c[0] -= j;
	for (int i= 1; i < c[0]; i++)
	{
		c[i] = c[i + j];
		cout << c[i];
	}
	cout << endl;
	return c;
}
bool cmp(Hands a, Hands b)
{
	return a.L*a.R < b.L*b.R;
}
int main()
{
	cin >> n;
	cin >> king.L >> king.R;
	king.lr();
	for (int i = 1; i < king.LF[0]; i++)
	{
		cj[i] = king.LF[i];
		if (i == king.LF[0] - 1)
		{
			cj[0] = i + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> government[i].L >> government[i].R;
		government[i].lr();
	}
	sort(government, government + n, cmp);

	//cout << endl;
	//cout << king.L<<" "<<king.R<<endl;
	//for (int i = 0; i <n; i++)
		//cout << government[i].L << ' ' << government[i].R << endl;
	//cout <<"*****"<< king.L / government[0].R;
	min0 = min0 > king.L / government[0].R ? min0 : king.L / government[0].R;
	for (int i = 1; i < n; i++)
	{
		gj1(gj(government[i - 1]), government[i]);
	}
	cout << min0 << endl;
	system("pause");
	return 0;
}