#include"rect.h"
#include<iostream>
using namespace std;
Rect::Rect(int l, int w)
{
	nLength = l;
	nWidth = w;
	cout << "constructing..." << endl;
}
Rect::~Rect()
{
	cout << "destruting..." << endl;
}
int Rect::Area_int()
{
	int s;
	s = nLength * nWidth;
	cout << "矩形面积为：" << s << endl;
}
