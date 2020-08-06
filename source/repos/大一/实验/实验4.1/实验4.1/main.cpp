#include<iostream>
#include<string>
using namespace std;
class CountStr
{
private:
	char c;
public:
	CountStr();
	int Length();
	~CountStr();
};
CountStr::CountStr()
{
	cout << "construct" << endl;
}
int CountStr::Length()
{
	c = getchar();
	int  n = 0;
	while ( c!= '\n')
	{
		c = getchar();
		n++;
	}
	return n;
}
CountStr::~CountStr()
{
	cout << "destruting" << endl;
}
int main()
{
	{
		int n;
		CountStr l;
		cout << "ÇëÊäÈëÒ»¶Î»°" << endl;
		n = l.Length();
		cout << n << endl;
	}
	system("pause");
	return 0;
}
