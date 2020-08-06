#include<iostream>
using namespace std;
class Sample
{
private:
	int x, y;
public:
	Sample(int a = 0, int b = 0)
	{
		this->x = a;
		this->y = b;
	}
	void Print()
	{
		cout << this->x << endl;
		cout << this->y << endl;
	}
};
int main()
{
	Sample obj(5, 10);
	obj.Print();
	system("pause");
	return 0;
}