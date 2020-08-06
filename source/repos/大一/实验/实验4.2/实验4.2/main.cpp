#include<iostream>
using namespace std;
class Rect
{ 
public:
	int Area_int();
    double Area_double();
    Rect(double l, double w);
    Rect(int l, int w);
    ~Rect();
 private:
    int nLength;
    int nWidth;
    double mLength;
    double mWidth;
};
Rect::Rect(double l, double w)
{
	mLength = l;
	mWidth = w;
	cout << "construct..." << endl;
}
Rect::Rect(int l, int w)
{
	nLength = l;
	nWidth = w;
	cout << "construct..." << endl;

}
Rect::~Rect()
{
	cout << "destruting..." << endl;
}
double Rect::Area_double()
{
	double s;
	s = mLength * mWidth;
	cout << "¾ØÐÎ1£º" << s << endl;
	return 0;
}
int Rect::Area_int()
{
	int s;
	s = nLength * nWidth;
	cout << "¾ØÐÎ2£º" << s << endl;
	return 0;
}
int main()
{
	{
		Rect jx1(4.2, 6.2);
		jx1.Area_double();
		Rect jx2(5, 8);
		jx2.Area_int();
	}
	system("pause");
	return 0;
}