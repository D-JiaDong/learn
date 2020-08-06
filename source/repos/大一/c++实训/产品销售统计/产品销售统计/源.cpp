#include<iostream>
using namespace std;
int main()
{
	void all(double m[4][5],double s[4][5]);
	void y_shengxiao(double m[4][5],double s[4][5]);
	void z_sum_shengxiao(double m[4][5],double s[4][5]);
	void z_shengxiao(double m[4][5],double s[4][5]);
	double m[4][5]= { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
	double s[4][5] = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
	/*for (int i = 0; i < 4; i++)
	{
		cout << "请输入第" << i + 1 << "周五种产品的生产量" << endl;
		for (int j = 0; j < 5; j++)
		{
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "请输入第" << i + 1 << "周五种产品的销售量" << endl;
		for (int j = 0; j < 5; j++)
		{
			cin >> s[i][j];
		}

	}*/
	while (true)
	{
		int xz;
		cin >> xz;
		if (xz == 1)
			z_shengxiao(m, s);
		else if (xz == 2)
			z_sum_shengxiao(m, s);
		else if (xz == 3)
			y_shengxiao(m, s);
		else if (xz == 4)
			all(m, s);
		else if (xz == 5)
		{
			cout << "退出" << endl;
			break;
		}
		else
			cout << "输入错误" << endl;
	}
	system("pause");
	return 0;
}
void all(double m[4][5],double s[4][5])
{
	double msum = 0,ssum = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			msum += m[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			ssum += s[i][j];
	cout << "Total product =" << msum << endl;
	cout << "Total sales = "<< ssum << endl;
}
void y_shengxiao(double m[4][5], double s[4][5])
{
	double ymsum[5] = { 0,0,0,0,0 }, yssum[5] = {0,0,0,0,0};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			ymsum[i] += m[j][i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			yssum[i] += s[j][i];
	cout << "                生产值           销售值" << endl;
	for (int i = 0; i < 5; i++)
		cout << "Product(" << i + 1 << ")" << "        " << ymsum[i] << "               " << yssum[i] << endl;
}
void z_sum_shengxiao(double m[4][5],double s[4][5])
{
	double zmsum[4] = { 0,0,0,0 }, zssum[4] = {0,0,0,0};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			zmsum[i] += m[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			zssum[i] += s[i][j];
	cout << "             生产值           销售值" << endl;
	for (int i = 0; i < 4; i++)
		cout << "Week(" << i + 1 << ")" << "        "<<zmsum[i] << "               " << zssum[i] << endl;
}
void z_shengxiao(double m[4][5],double s[4][5])
{
	cout << "每种产品每周的生产值" << endl;
	for (int i = 0; i < 4; i++)
		cout << "Week(" << i + 1 << ")" << m[i][0] << " " << m[i][1] << " "
		<< m[i][2] << " " << m[i][3] << " " << m[i][4] << endl;
	cout << "每种产品每周的销售值" << endl;
	for (int i = 0; i < 4; i++)
		cout << "Week(" << i + 1 << ")" << s[i][0] << " " << s[i][1] << " "
		<< s[i][2] << " " << s[i][3] << " " << s[i][4] << endl;
}

