#include<iostream>
using namespace std;
int N;
int main()
{
	cin >> N;
	int i;
	for (i = 0;; i++)
		if (i*(i + 1) / 2 >= N)
		{
			i--;
			break;
		}
	if ((i + 1) % 2 == 0)
		cout << N - i * (i + 1) / 2 << "/" << i + 2 - (N - i * (i + 1) / 2) << endl;
	else
		cout << i + 2 - (N - i * (i + 1) / 2) << "/" << N - i * (i + 1) / 2 << endl;
	system("pause");
	return 0;
}