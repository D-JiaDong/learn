#include<iostream>
using namespace std;
template<typename T, int size>
class Array
{
private:
	T a[size];
public:
	Array();
	T &operator[](int i);
	void print();
};
template<typename T, int size>
Array<T, size>::Array()
{
	T a1;
	int a2 = sizeof(a1);
	for (int i = 0; i < size; i++)
		if (a2 == 1)
			a[i] = 65;
		else
			a[i] = 0;
}
template<typename T, int size>
T &Array<T, size>::operator[](int i)
{
	if (i < 0 || i >= size)
	{
		cout << "´íÎó" << endl;
		exit(0);
	}
	return a[i];
}
template<typename T, int size>
void Array<T, size>::print()
{
	for (int i = 0; i < size; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int main()
{
	Array<int, 4> m;
	Array<char, 6> n;
	m[1] = 6;
	m.print();
	n.print();
	system("pause");
	return 0;
}
