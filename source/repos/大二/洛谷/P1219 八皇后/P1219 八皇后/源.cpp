#include<iostream>
using namespace std;
int visit[15][2];           //�жϵ�ǰ�����Ƿ�������
int bhh[15];                //����������
int k[50][2];               //�жϵ�ǰ���������Խ����Ƿ�������
int n;                     //���̴�С
int cou;                   //��ǰ�������Ӹ���
int coun;                 //�������
void dfs(int x,int y)
{
	if (visit[x][0] == 1 || visit[y][1] == 1 || k[y - (-1)*x + n][0] == 1 || k[y - x + n][1] == 1)//���жԽ����������� return
		return;
	cou++;
	visit[x][0] = 1; visit[y][1] = 1;               //��ǵ�ǰ������������
	k[y - (-1)*x + n][0] = 1; k[y - x + n][1] = 1;    //��ǵ�ǰ�������ڶԽ���
	bhh[x-1] = y;                                    //��Ǹ���������                          
	if (cou == n)                                    //������Ӹ����ﵽ�涨��Ŀ
	{
		coun++;                                     //���������һ
		if (coun < 4)								//���ǰ����
		{
			for (int i = 0; i < n; i++)
				cout << bhh[i] << ' ';
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++)                //������һ��
	{                            
		if (i + 1 >= y - 1 && i + 1 <= y + 1)  //�ų���ǰλ�õ��·� ���·� ���·�
			continue;
		dfs(x + 1, i + 1);                     //����
	}
	//����
	visit[x][0] = 0; visit[y][1] = 0;          
	k[y - (-1)*x+n][0] = 0; k[y - x+n][1] = 0;
	cou--;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)  //�Ե�һ�е�ÿһ������
		dfs(1, i + 1);
	cout << coun << endl;
	system("pause");
	return 0;
}