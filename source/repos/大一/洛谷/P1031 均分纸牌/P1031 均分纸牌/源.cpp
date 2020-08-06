#include<iostream>
using namespace std;
int n, a[105];
int sum,ave;
int num;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ave = sum / n;
	//cout << ave << endl;
	for (int i = 0; i < n; i++)
		a[i] = a[i] - ave;
	/*for (int j = 0; j < n; j++)
		cout << a[j] << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
		{
			a[i + 1] += a[i]; a[i] = 0;
			num++;
			/*for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;*/
		}
		else if (a[i] < 0)
		{
			a[i + 1] += a[i]; a[i] = 0;
			num++;
			/*for (int j = 0; j< n; j++)
				cout << a[j] << " ";
			cout << endl;*/
		}
		else
			continue;
	cout << num << endl;
	system("pause");
	return 0;
}