#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	char a[100], b[100];
	ofstream she;
	she.open("stu.txt");
	cout << "д���ļ�" << endl;
	cout << "����������:" << endl;
	//cin.getline(data, 100);
	cin >> a;
	she << a << endl;
	cout << "������ѧ��: " << endl;
	//cin.getline(data, 100);
	cin >> b;
	//cin.ignore();
	she << b << endl;
	she.close();
	ifstream he;
	he.open("stu.txt");
	cout << "�����ļ�" << endl;
	he >> a;
	cout << "������" << a << endl;
	he >> b;
	cout << "ѧ�ţ�" << b << endl;
	he.close();
	system("pause");
	return 0;
}