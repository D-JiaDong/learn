#include<iostream>
using namespace std;
int a[100][100];
int main()
{
	int n;
	cin >> n;
	a[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		int k = i+1;//��ʼ����i�еڶ���Ҫ�ӵ���
		for (int j = 0; j < n - i; j++)
		{
			if (j == 0 && i != 0)//������ǵ�һ�е����ǵ�һ�У����͵�����һ�еĵڶ���Ԫ�ؼ�һ
				a[i][j] = a[i - 1][j + 1] - 1;
			if (j > 0)//��������ǵ�һ�У����͵��ڸ��е���һ�м�k
				a[i][j] = a[i][j - 1] + k;
			cout << i + 1 << "��" << j + 1 << "��" <<"  "<<a[i][j]<< endl;
			k++;//ÿ�н�����k++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			cout << a[i][j]<<" ";
		cout << endl;
	}
	system("pause");
	return 0;
}