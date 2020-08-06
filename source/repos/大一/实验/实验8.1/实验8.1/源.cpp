#include<iostream>
#include<string>
using namespace std;
int i, j;
class Matrix
{
protected:
	int a[2][3];
public:
	Matrix() {}
	void Input()
	{
		cout << "请输入一个二行三列矩阵:" << endl;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 3; j++)
				cin >> a[i][j];
	}
	Matrix operator+(Matrix &ju)
	{
		Matrix temp;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 3; j++)
				temp.a[i][j] = a[i][j] + ju.a[i][j];
		return temp;
	}
	void Display()
	{
		cout << "矩阵相加后:" << endl;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 3; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}

	}
};
int main()
{
	Matrix m, n, p;
	m.Input();
	n.Input();
	p = m + n;
	p.Display();
	system("pause");
	return 0;
}