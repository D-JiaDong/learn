//题目十：最少钱币数
//【问题描述】
//这是一个古老而又经典的问题。用给定的几种钱币凑成某个钱数，一般而言有
//多种方式。例如：给定了6种钱币面值为2、5、10、20、50、100，用来凑 15元，
//可以用5个2元、1个5元，或者3个5元，或者1个5元、1个10元，等等。显然，最
//少需要2个钱币才能凑成15元。
//你的任务就是，给定若干个互不相同的钱币面值，编程计算，最少需要多少个钱
//币才能凑成某个给出的钱数。
//【要求】（代码需加注释）
//【数据输入】输入可以有多个测试用例。每个测试用例的第一行是待凑的钱数值
//M（1 <= M <= 2000，整数），接着的一行中，第一个整数K（1 <= K <= 10）表
//示币种个数，随后是K个互不相同的钱币面值Ki(1 <= Ki <= 1000)。输入M = 0时结束。
//【数据输出】每个测试用例输出一行，即凑成钱数值M最少需要的钱币个数。如果
//凑钱失败，输出“Impossible”。你可以假设，每种待凑钱币的数量是无限多的。
//【样例输入】
//15
//6 2 5 10 20 50 100
//1
//1 2
//0
//【样例输出】
//2
//Impossible
#include<iostream>
using namespace std;
int main()
{
	int daicou[100];
	int N[10000],z[10000];
	int k = 0;
	while (true)
	{
		int quxiao(int a, int b);
		cin >> daicou[k];
		if (daicou[k] == 0)
			break;
		for (int i = 0; i < 10000; i++)
			N[i] = 100000;
		//初始化要凑i元需要的最少钱币数，且设定为很大
		N[0] = 0;
		//初始化凑0元需要的钱币数为零，作为递归的结束
		int mianzhi[11];
		//定义足够大的数组用来存放币种面值
		int bizhong;
		cin >> bizhong;
		//定义币种个数，并赋值
		for (int i = 0; i < bizhong; i++)
		{
			cin >> mianzhi[i];
		}
		//完成输入部分
		for (int i = 0; i <= daicou[k]; i++)//从零开始依次求出N[i];
		{
			for (int j = 0; j < bizhong; j++)
				if (i >= mianzhi[j])//选择面值小于待凑金额
				{
					//cout << "N[" << i << "]=quxiao(N[" << i << "-" << mianzhi[j] << "]+1," << N[i] << ')' << endl;
					N[i] = quxiao(N[i - mianzhi[j]] + 1, N[i]);
				}
			//cout << "N[" << i << "]=" << N[i] << endl;
			//cout << "............................................." << endl;
		}
		z[k] = N[daicou[k]];
		k++;
	}
	if (daicou[k] == 0)
	{
		for(int i=0;i<k;i++)
		if (z[i] == 100000)
			cout << "Impossible" << endl;
		else
			cout << z[i] << endl;
	}
	system("pause");
	return 0;
}
int quxiao(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}