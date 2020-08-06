#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	char a[100], b[100];
	ofstream she;
	she.open("stu.txt");
	cout << "写入文件" << endl;
	cout << "请输入姓名:" << endl;
	//cin.getline(data, 100);
	cin >> a;
	she << a << endl;
	cout << "请输入学号: " << endl;
	//cin.getline(data, 100);
	cin >> b;
	//cin.ignore();
	she << b << endl;
	she.close();
	ifstream he;
	he.open("stu.txt");
	cout << "读出文件" << endl;
	he >> a;
	cout << "姓名：" << a << endl;
	he >> b;
	cout << "学号：" << b << endl;
	he.close();
	system("pause");
	return 0;
}