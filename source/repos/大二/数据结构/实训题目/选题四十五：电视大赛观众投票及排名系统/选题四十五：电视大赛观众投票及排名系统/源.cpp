#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	string name; /*ѡ������*/
	int num;  /*ѡ�ֱ��*/
	int score=0;  /*ѡ�ֵ÷�*/
	int tax;  /*ѡ������*/
};
node  user[10];
int n;
bool cmp(node a,node b)
{
	return a.score > b.score;
}
int main() {
	cout << "����ѡ��������" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "�����" << i + 1 << "λѡ������" << endl;
		cin >> user[i].name;
		user[i].num = i + 1;
	}
	cout << "��ʼͶƱ" << endl;
	while (1)
	{
		int i;
		cin >> i;
		if (i == 0)
			break;
		else
			user[i - 1].score++;
	}
	sort(user, user + n, cmp);
	int ta = 1;               //��ŵ�ǰ����
	int sor = user[0].score;  //��ǰ��С��Ʊ��
	//�Ӹߵ��ͱ���ѡ��   ��ѡ������
	for (int i = 0; i < n; i++)
	{
		if (user[i].score == sor)
			user[i].tax = ta;
		else
		{
			ta++;
			sor = user[i].score;
			user[i].tax = i+1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (user[i].tax == 1)
		{
			cout << "�ھ���" << '\t' << user[i].name << '\t' << "Ʊ����" << user[i].score << endl;
			continue;
		}
		if(user[i].tax==2)
		{
			cout << "�Ǿ���" << '\t' << user[i].name << '\t' << "Ʊ����" << user[i].score << endl;
			continue;
		}
		if (user[i].tax == 3)
		{
			cout << "������" << '\t' << user[i].name << '\t' << "Ʊ����" << user[i].score << endl;
			continue;
		}
		cout<<"��"<<i+1<<"��"<<'\t'<<user[i].name<<'\t' << "Ʊ����" << user[i].score << endl;
	}
	system("pause");
	return 0;
}