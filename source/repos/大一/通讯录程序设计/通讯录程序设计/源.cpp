#include<iostream>
#include<string>
#include<fstream>
using namespace std;
typedef class tongxunlu
{
private:
	string xm;
	string jg;
	string d1,d2;
	string yx;
public:
	double luru(tongxunlu a[]);
	double liulan(tongxunlu a[]);
	double xiugai(tongxunlu a[]);
}ooo;
tongxunlu a[30]; int n;
double tongxunlu::luru(tongxunlu a[])
{
	ofstream xieru("abc.txt", ios::out);
	if (!xieru)
	{
		cout << "无法打开文件" << endl;
		return -1;
	}
	cout << "请输入需要录入联系人个数" << endl;
	cin >> n;
	cout << "请依次输入联系人姓名,籍贯,电话号码1,电话号码2以及电子邮箱:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].xm >> a[i].jg >> a[i].d1 >> a[i].d2 >>a[i].yx;
		xieru << a[i].xm << endl;
		xieru << a[i].jg << endl;
		xieru << a[i].d1 << endl;
		xieru << a[i].d2 << endl;
		xieru << a[i].yx << endl;
	}
	xieru.close();
	return 0;
}
double tongxunlu::liulan(tongxunlu a[])
{
	ifstream liulan("abc.txt", ios::in);
	if (!liulan)
	{
		cout << "无法打开文件" << endl;
		return -1;
	}
	string liu;
    while(!liulan.eof())
	{
		getline(liulan, liu);
		cout<<liu << endl;
	}
	return 0;
}
double tongxunlu::xiugai(tongxunlu a[])
{
	ifstream duchu("abc.txt", ios::in);
	if (!duchu)
	{
		cout << "无法打开文件" << endl;
		return -1;
	}
	string du;
	tongxunlu b[30];
	for (int i = 0; i < n; i++)
	{
		getline(duchu,du);
		b[i].xm = du;
		getline(duchu, du);
		b[i].jg = du;
		getline(duchu, du);
		b[i].d1 = du;
		getline(duchu, du);
		b[i].d2 = du;
		getline(duchu, du);
		b[i].yx = du;
		
	}
	cout << "请输入您要修改的的联系人" << endl;
	string xm1; int jilu = 0;
	cin >> xm1;
	for(int i=0;i<n;i++)
		if (b[i].xm==xm1)
		{
			jilu = i;
			break;
		}
	cout<<"请选择您要修改的内容"<<endl;
	cout << "1.姓名  2.籍贯  3.电话1  4.电话2  5.邮箱" << endl;
	int xz;
	cin >> xz;
	cout << "请输入要改为的内容:" << endl;
	string gaiwei;
	cin >> gaiwei;
	if (xz == 1)
		b[jilu].xm = gaiwei;
	else if (xz == 2)
		b[jilu].jg= gaiwei;
	else if (xz == 3)
		b[jilu].d1= gaiwei;
	else if (xz == 4)
		b[jilu].d2 = gaiwei;
	else if (xz == 5)
		b[jilu].yx = gaiwei;
	else
		cout << "无该选项" << endl;
	ofstream xieru("abc.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		xieru << b[i].xm << endl;
		xieru << b[i].jg << endl;
		xieru << b[i].d1 << endl;
		xieru << b[i].d2 << endl;
		xieru << b[i].yx << endl;
	}
	return 0;
}
double chaxun()
{
	bool boo = true;
	while (boo)
	{
		ifstream she2("abc.txt", ios::in);
		while (!she2)
		{
			cout << "无法打开文件" << endl;
			return -1;
		}
		cout << "请选择查询联系人姓名:" << endl;
		string xingm;
		cin >> xingm;
		char p[10]; int i = 0;
		while (!she2.eof())
		{
			she2.getline(p, 10, '\n');
			if (p == xingm)
			{
				she2.getline(p, 10, '\n');
				cout << "籍贯：" << p << endl;
				she2.getline(p, 20, '\n');
				cout << "电话1:" << p << endl;
				she2.getline(p, 20, '\n');
				cout << "电话2:"<< p << endl;
				she2.getline(p, 10, '\n');
				cout << "邮箱:" << p << endl;
				i++;
			}
		}
		if (i == 0)
			cout << "无该联系人" << endl;
		she2.close();
		cout << "是否还要继续查询?是:1 否:2" << endl;
		int b;
		cin >> b;
		if (b == 2)
			boo = false;
	}
	return 0;
}
int main()
{
	while (true)
	{
		ooo b;
		cout << "请输入您要进行的操作" << endl;
		cout << "a.信息录入" << "  " << "b.信息浏览" << endl;
		cout << "c.信息查询" << "  " << "d.信息修改" << endl;
		cout << "e.退出系统" << endl;
		char cz;
		cin >> cz;
		if (cz == 'a')
			b.luru(a);
		else if (cz == 'b')
			b.liulan(a);
		else if (cz == 'c')
			chaxun();
		else if (cz == 'd')
			b.xiugai(a);
		else if (cz == 'e')
			break;
		else
			cout << "无该选项" << endl;
	}
	system("pause");
	return 0;
}
