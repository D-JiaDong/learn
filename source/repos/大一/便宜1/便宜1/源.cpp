//题目描述：
//公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
//返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
#include<iostream>
using namespace std;
int main()
{
	double temp;
	int n, i, j, k;
	double cha[20];
	double cos[1][2];
	double costs[20][2];
	//输入人数
	cout << "请输入面试人数" << endl;
	cin >> n;
	//输入数据
	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
		{
			cin >> costs[i][j];
		}
	//计算差值
	for (i = 0; i < n; i++)
	{
		cha[i] = costs[i][0] - costs[i][1];
	}
	//选择法排序并记录每个人应该去的地方所需的钱
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (cha[k] > cha[j])
			{
				k = j;
			}
		temp = cha[i];
		cha[i] = cha[k];
		cha[k] = temp;
		//定义空数组用于转换，每次选择法两个排序转换的数组
		cos[0][0] = costs[i][0];
		cos[0][1] = costs[i][1];
		//将数组转化成排序后形成类似于[a地钱，0]，[a地钱，0],[0,b地钱],[0,b地钱]这种形式
		if (i < n / 2)
		{
			costs[i][0] = costs[k][0];
			costs[i][1] = 0;
		}
		else
		{
			costs[i][1] = costs[k][1];
			costs[i][0] = 0;
		}
		costs[k][0] = cos[0][0];
		costs[k][1] = cos[0][1];
	
	}
	double all1 = 0, all2 = 0;
	//a地
	for (i = 0; i < n / 2; i++)
		all1 = all1 + costs[i][0];
	//b地
	for (i = n / 2; i < n; i++)
		all2 = all2 + costs[i][1];
	cout << all1 + all2 << endl;
	/*排序输出
	for (i = 0; i < n; i++)
		cout << cha[i];*/
	system("pause");
	return 0;
}