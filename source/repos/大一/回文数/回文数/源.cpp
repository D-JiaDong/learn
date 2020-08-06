#include<iostream>
using namespace std;
int a[101],b[101];
char d[101];
int l=0,step=0;
int n;
bool huiwen(int a[])
{
	for (int i = 0,j = l - 1; i < l; i++,j--)
		if (a[i] != a[j])
			return false;
	return true;
}
int main()
{
	cin >> n;
	cin >> d;
	for(int i=0;i<strlen(d);i++)
		if (d[i]>=65 && d[i]<=71)
			a[l++] = d[i] - 55;
		else
			if(d[i]>=48&&d[i]<=57)
				a[l++] =d[i] - 48;
	/*for (int i = 0, j = l-1; i <=l/2; i++, j--)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}*/
	while (true)
	{
		if (step>= 30)
		{
			cout << "Impossible!" << endl;
			break;
		}
		if (huiwen(a))
		{
			cout << "STEP=" << step << endl;
			break;
		}
		int jin = 0;
		for (int i = 0, j = l - 1; i < l; i++, j--)
		{
			b[i] = (a[i] + jin + a[j]) % n;
			jin = (a[i] + jin + a[j]) / n;
		}
		if (jin != 0)
			b[l++] = 1;
		for (int i = 0; i < l; i++)
			a[i] = b[i];
		step++;
	}
	system("pause");
	return 0;
}
