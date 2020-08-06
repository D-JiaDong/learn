//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	//函数在p0位置插入字符串s中pos开始的前n个字符
//	//string &insert(int p0, const char *s);
//	string str = "abcdefghijklmn";
//	str.insert(1, "@#$%");
//	cout << str << endl; //a@#$%bcdefghijklmn
//
//	//string &insert(int p0, const char *s, int n);
//	str = "abcdefghijklmn";
//	str.insert(1, "@#$%",2);
//	cout << str << endl;//a@#bcdefghijklmn
//
//	//string &insert(int p0, const string &s, int pos, int n);
//	str = "abcdefghijklmn";
//	str.insert(1, "@#$%", 2,3);//包前包后
//	cout << str << endl;//a$%bcdefghijklmn
//
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<iomanip>
using namespace std;
int d[9][9];//d数组 存放每个顶点到每个顶点的最短路径长度
int p[9][9];//p数组 存放最短路径
int main() {
	//初始化数组
	for (int i = 0; i <5; i++)
		for (int j = 0; j < 5; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 0xfffffff;
			p[i][j] = j+1;
		}
	//向邻接矩阵中写入权值
	{
		d[0][1] = 50;
		d[1][4] = 80;
	    d[2][1] = 30; d[2][3] = 20; 
		d[3][4] = 70; 
		d[4][0] = 65; d[4][2] = 100; 
	}
	//更新存放最短距离的d邻接矩阵  更新存放路径的p数组
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}
			}
		cout << "当k="<<k+1<<"时候" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (d[i][k]+d[k][j] >= 0xfffffff)
					cout << setw(4) << "**";
				else
					cout << setw(4) << d[i][k]+d[k][j];
			}
			cout << endl;
		}
		cout << "B"<<k+1<<endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (d[i][j] == 0xfffffff)
					cout << setw(4) << "**";
				else
					cout << setw(4) << d[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "R数组" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(4) << p[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
