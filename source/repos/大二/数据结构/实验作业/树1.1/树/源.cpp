#include<iostream>
#include<queue>
using namespace std;
char pred[9] = { 'a','b','h','f','d','e','c','k','g' };//����
char eplg[9] = { 'h','b','d','f','a','e','k','c','g' };//����
int n = 9;
void df(int cur, int l, int r, int lorr, int ceng)
//������±�cur����������������������ķ�Χ����߽�l  �ұ߽�r��,
//��������lorr(0.1�ж�)  ����������
{
	if (l == r)
	{
		for (int j = 0; j < ceng; j++)
			cout << '\t';
		cout << '(' << lorr << ')' << pred[cur] << endl;
	}
	//���������ΪҶ�ӽڵ�ʱ ���
	if (cur >= n || l >= r)
		return;
	for (int j = 0; j < ceng; j++)
		cout << '\t';
	if (cur != 0)
		cout << '(' << lorr << ')' << pred[cur] << endl;
	else
		cout<< pred[cur] << endl;
	int i;
	for (i = l; i <= r; i++)
	{
		if (eplg[i] == pred[cur])
		{
			break;
		}
	}
	//�������� ���Ҹ���������±� 
	df(cur + 1, l, i - 1, 0, ceng + 1);          //���������������
	df(cur + (i - l + 1), i + 1, r, 1, ceng + 1);//��������Һ�������
}
int  main()
{
	df(0, 0, n - 1, 0, 0);
	system("pause");
	return 0;
}



