#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream he;
	he.open("abc.txt", ios::in);
	if (!he)
	{
		cout << "open abc error" << endl;
		return -1;
	}
	int n=0;
	while (!he.eof())
	{
		char a=he.get();
		cout << a;
		n++;
	}
	cout << endl;
	cout <<"�ֽ�����"<< n << endl;
	system("pause");
	return 0;
}