#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	ifstream file("test.txt");
	string line;
	int n, count = 0;
	ofstream outfile("test2.txt", ios::out | ios::trunc);
	cout << "Please input the line number you want to del:" << endl;
	cin >> n;
	while (!file.eof()) {
		getline(file, line);
		if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
			outfile << line << endl;
		count++;
	}
	outfile.close();
	file.close();
	ofstream outfile1("test.txt", ios::out | ios::trunc);
	fstream file1("test2.txt");
	while (!file1.eof()) {
		getline(file1, line);
		outfile1 << line << endl;
	}
	outfile1.close();
	file1.close();
	system("del test2.txt");//删除中间文件
	return 0;
}

