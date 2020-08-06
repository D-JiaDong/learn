#include<iostream>
#include<stack>
using namespace std;
int adjacent[10][10];
int n=4;
stack<int> stac;
//�ж��Ƿ�Ϊ��ͨͼ
bool connected()
{
	for (int i = 0; i < n; i++)
	{
		bool bo = false;
		for (int j = 0; j < n;j++)
			if (adjacent[i][j] == 1)
			{
				bo = true;
				break;
			}
		if (!bo)
			return false;
		else
			continue;
	}
	return true;
}
//����ͼ����ȶ������
int num_jd()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int cou = 0;
		for (int j = 0; j < n; j++)
		{
			if (adjacent[i][j] == 1)
				if (i == j)
					cou+=2;
				else
					cou++;
		}
		if (cou % 2 != 0)
			sum++;
	}
	return sum;
}
//����һ����ȶ���
int node_jd()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int cou = 0;
		for (int j = 0; j < n; j++)
		{
			if (adjacent[i][j] == 1)
				if (i == j)
					cou += 2;
				else
					cou++;
		}
		if (cou % 2 != 0)
			return i;
	}
}
//�������������ŷ��(��)·
void dfs(int x)
{
	stac.push(x);
	int X = -1;
	for (int j = 0; j < n; j++)
	{
		if (adjacent[x][j] == 1)
		{
			adjacent[x][j] = 0;
			adjacent[j][x] = 0;
			X = j;
			break;
		}
	}
	if (X == -1)
	{
		int a[20];
		int i = 0;
		while (!stac.empty())
		{
			a[i++]=stac.top();
			stac.pop();
		}
		for (int j = i - 1; j >= 0; j--)
			cout << a[j]+1 << ' ';
		cout << endl;
	}
	if (X != -1)
		dfs(X);
}
int main()
{
	while (1)
	{
		cout << "ִ�г���1        �˳���0" << endl;
		int login;
		cin >> login ;
		if (login != 1)
			break;
		cout << "������ͼ�Ľڵ�����";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				adjacent[i][j] = rand() % 2;
				adjacent[j][i] = adjacent[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << adjacent[i][j] << ' ';
			cout << endl;
		}
		if (!connected())
		{
			cout << "����ͨͼ��" << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << adjacent[i][j] << ' ';
				cout << endl;
			}
			continue;
		}
		int num = num_jd();
		if (num!=0&&num!=2)
		{
			cout << "��(��)ŷ��ͼ��" << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << adjacent[i][j] << ' ';
				cout << endl;
			}
			continue;
		}
		if (num == 2)
		{
			cout << "��ŷ��ͼ��" << endl;
			int star=node_jd();
			dfs(star);
		}
		if (num == 0)
		{
			cout << "ŷ��ͼ��" << endl;
			dfs(rand()%n);
		}
	}
	system("pause");
	return 0;
}