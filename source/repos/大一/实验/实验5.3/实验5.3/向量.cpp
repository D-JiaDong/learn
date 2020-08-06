#include<iostream>
using namespace std;
class Vector
{
public:
	double x, y;
	Vector()
	{
		cout << "请输入一个点的坐标位置X和Y" << endl;
		cin >> x >> y;
	}
	friend double jia(Vector a, Vector b);
	friend double jian(Vector a, Vector b);
};
double jia(Vector a,Vector b)
{
	double x, y;
	x = a.x + b.x;
	y = a.y + b.y;
	cout <<"相加后坐标为:"<<"(" << x << "," << y << ")" << endl;
	return 0;
}
double jian(Vector a, Vector b)
{
	double x, y;
	x = a.x - b.x;
	y = a.y - b.y;
	cout << "相减后坐标为:" << "(" << x << "," << y << ")" << endl;
	return 0;
}
int main()
{
	Vector a, b;
	jia(a, b);
	jian(a, b);
	system("pause");
	return 0;
}
