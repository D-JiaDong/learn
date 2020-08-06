#include<iostream>
#include<string>
using namespace std;
class Vector
{
private:
	int x;
	int y;
public:
	Vector()
	{
		x = 0;
		y = 0;
	}
	Vector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	string ToString()
	{
		return"(" + to_string(x) + "," + to_string(y) + ")";
	}
	friend Vector Add(Vector v1, Vector v2);
	friend Vector Sub(Vector v1, Vector v2);
};
Vector Add(Vector v1, Vector v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y);
}
Vector Sub(Vector v1, Vector v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y);
}
int main()
{
	Vector v1(1, 1), v2(3, 4);
	cout << Add(v1, v2).ToString() << endl;
	cout << Sub(v1, v2).ToString() << endl;
	system("pause");
	return 0;
}
