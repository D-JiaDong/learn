//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	int x; int y;//ǰ������
//	int t=0; int g=0;//���·�������ͨ�������δ����Ϊ0������Ϊ1��
//};
//A a[100][100];
//A L[100][100];//��¼���·���� 
//int nx[100][2];
//int m, n,k;
//int c[4][2] = { 1,0,0,1,0,-1,-1,0 };
//int D=0xfffffff;
//void def(int h, int z,int d)//�������꣬·������
//{
//	if (h<1 || h>m || z<1 || z>n || a[h][z].g == 1 || a[h][z].t == 0 || d >= D)
//		return;
//	a[h][z].g = 1;
//	if (h == m && z == n)
//	{
//		if (d < D)
//		{
//			D = d;
//			for (int i = 0;; i++)
//			{
//				L[h][z] = a[h][z];
//				int o = L[h][z].x;
//				int p = L[h][z].y;
//				h = o;
//				z = p;
//				if (h == 0 && z == 1)
//					break;
//			}
//		}
//		a[m][n].g = 0;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		int o = a[h + c[i][0]][z + c[i][1]].x;
//		int p = a[h + c[i][0]][z + c[i][1]].y;
//		a[h + c[i][0]][z + c[i][1]].x = h;
//		a[h + c[i][0]][z + c[i][1]].y = z;
//		def(h + c[i][0], z + c[i][1],d+1);
//		a[h + c[i][0]][z + c[i][1]].x = o;
//		a[h + c[i][0]][z + c[i][1]].y = p;
//	}
//	a[h][z].g = 0;
//}
//int main()
//{
//	//�����ͼ
//	cin >> m >> n;
//	for (int i = 1; i <=m; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> a[i][j].t;
//	a[1][1].x = 0; a[1][1].y=1;
//	def(1, 1, 0);
//	//�ӳ����������ǰ����� �����·��
//	while (m != 0 || n != 1)
//	{
//		nx[k][0] = m; nx[k][1] = n;
//		k++;
//		int o = L[m][n].x;
//		int p = L[m][n].y;
//		m = o; n = p;
//	}
//	for (int i = k - 1; i >= 0; i--)
//	{
//		cout << "��" << k-i << "��\t(" << nx[i][0] << "," << nx[i][1] <<")"<< endl;
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<stack>
using namespace std;
class A
{
public:
	int x; int y;//ǰ������
	int t = 0; int g = 0;//���·�������ͨ�������δ����Ϊ0������Ϊ1��
};
stack<A> S;
A a[100][100];
//stack L[100][100];//��¼���·���� 
int nx[100][2];
int m, n, k;
int c[4][2] = { 1,0,0,1,0,-1,-1,0 };
int D = 0xfffffff;
void def(int h, int z, int d)//�������꣬·������
{
	if (h<1 || h>m || z<1 || z>n || a[h][z].g == 1 ||a[h][z].t == 0 || d >= D)
		return;
	a[h][z].g = 1;
	if (h == m && z == n)
	{
		if (d < D)
		{
			D = d;
			if (!S.empty())
			{
				int k = S.size();
				for (int j = 0; j < k; j++)
					S.pop();
			}
			for (int i = 0;; i++)
			{
				S.push(a[h][z]);
				int o = a[h][z].x;
				int p = a[h][z].y;
				h = o;
				z = p;
				if (h == 1 && z == 1)
					break;
			}
		}
		a[m][n].g = 0;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int o = a[h + c[i][0]][z + c[i][1]].x;
		int p = a[h + c[i][0]][z + c[i][1]].y;
		a[h + c[i][0]][z + c[i][1]].x = h;
		a[h + c[i][0]][z + c[i][1]].y = z;
		def(h + c[i][0], z + c[i][1], d + 1);
		a[h + c[i][0]][z + c[i][1]].x = o;
		a[h + c[i][0]][z + c[i][1]].y = p;
	}
	a[h][z].g = 0;
}
int main()
{
	//�����ͼ
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j].t;
	a[1][1].x = 0; a[1][1].y = 1;
	def(1, 1, 0);
	//�ӳ����������ǰ����� �����·��
	int i = S.size();
	for (int j = 0; j < i; j++)
	{
		A b = S.top(); S.pop();
		cout << "��" << j+1 << "��\t(" << b.x << "," << b.y << ")" << endl;
	}
	cout << "��" << i+1 << "��\t(" << m << "," << n << ")" << endl;
	system("pause");
	return 0;
}
