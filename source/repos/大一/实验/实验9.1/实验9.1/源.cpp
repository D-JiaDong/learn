#include<iostream>
using namespace std;
template<typename T>
T pai(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	return 0;
}
template<typename T>
T input(T a[], int n)
{
	cout << "请输入该数组" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	return 0;
}
template<typename T>
T display(T a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
	return 0;
}
int main()
{
	int a[20];
	double b[20];
	int n1, n2;
	cout << "请输入int类型数组元素个数" << endl;
	cin >> n1;
	input(a, n1);
	pai(a, n1);
	display(a, n1);
	cout << "请输入double类型数组元素个数" << endl;
	cin >> n2;
	input(b, n2);
	pai(b, n2);
	display(b, n2);
	system("pause");
	return 0;
}
