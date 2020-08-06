#include<iostream>
using namespace std;
int a[100][100];
int main()
{
	int n;
	cin >> n;
	int k = -1;
	for (int j = n; j > 0; j -= 2)
	{
		k++;
		if (j == n)
			a[k][k] = 1;
		else
			a[k][k] = a[k - 1][k - 1] + 4 * (j + 1);//第j+1圈的第一组的第一个元素
		for (int i = 0; i < j - 1; i++)
		{
			if (i > 0)
			a[k][k + i] = a[k][k + i - 1] + 1;//第j+1圈的第一组的第2到j(i)元素
			cout << k+1 <<"行"<< k + i+1 << "列：" << a[k][k + i] << endl;
			a[k + i][k + j - 1] = a[k][k + i] + j - 1;//第j+1圈的第二组的第1到j(i)个元素
			cout << k + i+1 << "行" << k + j - 1+1 << "列：" << a[k + i][k + j - 1] << endl;
			a[k + j - 1][k + j - 1 - i] = a[k + i][k + j - 1] + j - 1;//第j+1圈的第三组的第1到j(i)个元素
			cout << k + j - 1+1 << "行" << k + j - 1 - i+1 << "列：" << a[k + j - 1][k + j - 1 - i] << endl;
			a[k + j - 1 - i][k] = a[k + j - 1][k + j - 1 - i] + j - 1;//第j+1圈的第四组的第1到j(i)个元素
			cout << k + j - 1 - i+1 << "行" << k+1<< "列：" << a[k + j - 1 - i][k] << endl;
			//cout << endl;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
	system("pause");
	return 0;
}