//**3������һ�������࣬ʵ�������ǰ�á�++������á�++�������ء�
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
		cout << "������һ��������ʵ�����鲿:"<<endl;
		cin >> shi >> xu;
	}
	friend Complex operator+(Complex &a, Complex &b)
	{
		Complex temp(a.shi + b.shi, a.xu + b.xu);
		return temp;
	}
	void print()
	{
		cout << "��Ӹ�����Ϊ:" << endl;
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