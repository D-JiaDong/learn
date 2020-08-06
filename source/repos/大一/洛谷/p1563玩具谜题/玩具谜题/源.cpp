#include<iostream>
using namespace std;
int fen[100001];
int n1[100001];
char n2[100001][11];
int m1[100001][2];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> n1[i] >> n2[i];
	for (int i = 0; i < m; i++)
		cin >> m1[i][0] >> m1[i][1];
	int k = 0;
	for (int i = 0; i < m; i++)
		if (n1[k] + m1[i][0] == 1)//ÄæÊ±Õë
		{
			if (k+m1[i][1] > n - 1)
				k = (k+m1[i][1]) % n;
			else
				k = k + m1[i][1];
			//cout << k<<endl;
			//cout << n2[k] << endl;
		}
		else//Ë³Ê±Õë
		{
			if (k-m1[i][1]<0)
				k = n-(-(k -m1[i][1]) % n);
			else
				k = k - m1[i][1];
			//cout << k << endl;
			//cout << n2[k] << endl;
		}
	cout << n2[k] << endl;
	system("pause");
	return 0;
}