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
		cout << "�޷����ļ�" << endl;
		return -1;
	}
	cout << "��������Ҫ¼����ϵ�˸���" << endl;
	cin >> n;
	cout << "������������ϵ������,����,�绰����1,�绰����2�Լ���������:" << endl;
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
		cout << "�޷����ļ�" << endl;
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
		cout << "�޷����ļ�" << endl;
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
	cout << "��������Ҫ�޸ĵĵ���ϵ��" << endl;
	string xm1; int jilu = 0;
	cin >> xm1;
	for(int i=0;i<n;i++)
		if (b[i].xm==xm1)
		{
			jilu = i;
			break;
		}
	cout<<"��ѡ����Ҫ�޸ĵ�����"<<endl;
	cout << "1.����  2.����  3.�绰1  4.�绰2  5.����" << endl;
	int xz;
	cin >> xz;
	cout << "������Ҫ��Ϊ������:" << endl;
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
		cout << "�޸�ѡ��" << endl;
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
			cout << "�޷����ļ�" << endl;
			return -1;
		}
		cout << "��ѡ���ѯ��ϵ������:" << endl;
		string xingm;
		cin >> xingm;
		char p[10]; int i = 0;
		while (!she2.eof())
		{
			she2.getline(p, 10, '\n');
			if (p == xingm)
			{
				she2.getline(p, 10, '\n');
				cout << "���᣺" << p << endl;
				she2.getline(p, 20, '\n');
				cout << "�绰1:" << p << endl;
				she2.getline(p, 20, '\n');
				cout << "�绰2:"<< p << endl;
				she2.getline(p, 10, '\n');
				cout << "����:" << p << endl;
				i++;
			}
		}
		if (i == 0)
			cout << "�޸���ϵ��" << endl;
		she2.close();
		cout << "�Ƿ�Ҫ������ѯ?��:1 ��:2" << endl;
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
		cout << "��������Ҫ���еĲ���" << endl;
		cout << "a.��Ϣ¼��" << "  " << "b.��Ϣ���" << endl;
		cout << "c.��Ϣ��ѯ" << "  " << "d.��Ϣ�޸�" << endl;
		cout << "e.�˳�ϵͳ" << endl;
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
			cout << "�޸�ѡ��" << endl;
	}
	system("pause");
	return 0;
}
