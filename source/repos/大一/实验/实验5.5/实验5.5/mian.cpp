#include <iostream>
using namespace std;
class B;
class A
{
private:
	int x;
public:
	A(int xx) { x = xx; }
	int Set(B&);
	int Get() { return x; }
};
class B
{
private:
	int x;
public:
	B(int xx) { x = xx; }
	friend  class A;
};
int A::Set(B &b)
{
	return x = b.x;
}
void main()
{
	A a(10);
	B b(20);
	cout << a.Get() << endl;
	a.Set(b);
	cout << a.Get() << endl;
	system("pause");
}
