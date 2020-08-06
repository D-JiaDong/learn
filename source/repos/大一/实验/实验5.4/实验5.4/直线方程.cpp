
#include<iostream>
using namespace std;
class Line
{
public:
	static int i;
	Line() { i++; }
	double a, b;
	double Print();
	friend double SetPoint(Line x1, Line x2);
};
double Line::Print()
{
		cout << "请输入第" << i << "个直线方程y=ax+b的两个参数a,b" << endl;
		cin >> a >> b;
		cout << "y=" << a << "x" << "+" << b << endl;
		return 0;
}
int Line::i = 0;
double  SetPoint(Line x1,Line x2 ) 
{
	double x, y;
	x = (x2.b - x1.b) / (x1.a - x2.a);
	y = x1.a*(x2.b - x1.b) / (x1.a - x2.a)+x1.b;
	cout << "(" << x << "," << y << ")" << endl;
	return 0;
}
int main()
{
	Line x1;
	x1.Print();
	Line x2;
	x2.Print();
	SetPoint(x1,x2);
	system("pause");
	return 0;
}