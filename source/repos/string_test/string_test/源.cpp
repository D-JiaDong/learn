//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	//������p0λ�ò����ַ���s��pos��ʼ��ǰn���ַ�
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
//	str.insert(1, "@#$%", 2,3);//��ǰ����
//	cout << str << endl;//a$%bcdefghijklmn
//
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<iomanip>
using namespace std;
int d[9][9];//d���� ���ÿ�����㵽ÿ����������·������
int p[9][9];//p���� ������·��
int main() {
	//��ʼ������
	for (int i = 0; i <5; i++)
		for (int j = 0; j < 5; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 0xfffffff;
			p[i][j] = j+1;
		}
	//���ڽӾ�����д��Ȩֵ
	{
		d[0][1] = 50;
		d[1][4] = 80;
	    d[2][1] = 30; d[2][3] = 20; 
		d[3][4] = 70; 
		d[4][0] = 65; d[4][2] = 100; 
	}
	//���´����̾����d�ڽӾ���  ���´��·����p����
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}
			}
		cout << "��k="<<k+1<<"ʱ��" << endl;
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
	cout << "R����" << endl;
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
