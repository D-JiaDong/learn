#include<iostream>
using namespace std;
int pin[5001][2];
int main()
{
	int n, s, a, b;
	//苹果数量，力气，椅子高度
	//手伸直的最大长度。
	cin >> n >> s;
	cin >> a >> b;
	int xi, yi;//苹果高度，力气
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> xi >> yi;
		if (a + b >= xi && yi <= s)
		{
			pin[j][0] = xi;
			pin[j][1] = yi;
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		int k = i;
		for (int i1 = i; i1 < j; i1++)
			if (pin[i1][1] < pin[k][1])
				k = i1;
		int temp = pin[i][1];
		pin[i][1] = pin[k][1];
		pin[k][1] = temp;
	}
	/*cout <<endl;
	for (int i = 0; i < j; i++)
		cout << pin[i][0] << " " << pin[i][1] << endl;*/
	int sum = 0;
	int N=0;
	for (int i = 0; i < j; i++)
	{
		sum += pin[i][1];
		if (sum <= s)
			N++;
	}
	cout << N << endl;
	system("pause");
	return 0;
}