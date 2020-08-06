//**3．定义一个复数类，实现运算符前置“++”与后置“++”的重载。
#include<iostream>
using namespace std;
class Complex
{
private:
	double shi, xu;
public:
	Complex(double x, double y)
	{
		shi = x; xu = y;
	}
	Complex() 
	{
		cout << "请输入一个复数的实部和虚部:"<<endl;
		cin >> shi >> xu;
	}
	friend Complex operator+(Complex &a, Complex &b)
	{
		Complex temp(a.shi + b.shi, a.xu + b.xu);
		return temp;
	}
	void print()
	{
		cout << "相加复数后为:" << endl;
		cout << shi << "+" << xu << "i" << endl;
	}
};
int main()
{
	Complex m, n;
	Complex p(0, 0);
	p = m + n;
	p.print();
	system("pause");
	return 0;
}