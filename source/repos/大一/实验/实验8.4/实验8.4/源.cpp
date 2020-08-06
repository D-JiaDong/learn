#include<iostream>
using namespace std;
int i, j;
class Matrix
{
	int a[2][3];
public:
	Matrix() {}
	/*void Input()
	{
		cout<<"请输入一个二行三列矩阵:"<<endl;
		for(i=0;i<2;i++)
			for(j=0;j<3;j++)
				cin>>a[i][j];
	}*/
	Matrix operator+(Matrix &ju)
	{
		Matrix temp;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 3; j++)
				temp.a[i][j] = a[i][j] + ju.a[i][j];
		return temp;
	}
	/*void Display()
	{
		cout<<"矩阵相加后:"<<endl;
		for(i=0;i<2;i++)
			{
				for(j=0;j<3;j++)
					cout<<a[i][j]<<"\t";
				cout<<endl;
			}

	}*/
	friend ostream &operator<<(ostream &stream, Matrix &m);
	friend istream &operator>>(istream &stream, Matrix &m);
};
istream &operator>>(istream &stream, Matrix &m)
{
	cout << "请输入一个二行三列矩阵:" << endl;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			stream >> m.a[i][j];
	return stream;
}
ostream &operator<<(ostream &stream, Matrix &m)
{
	cout << "矩阵相加后为:" << endl;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			stream << m.a[i][j] << "\t";
		cout << endl;
	}
	return stream;
}
int main()
{
	Matrix m, n, p;
	/*m.Input();
	n.Input();
	p=m+n;
	p.Display();
	system("pause");*/
	cin >> m;
	cin >> n;
	p = m + n;
	cout << p;
	system("pause");
	return 0;
}