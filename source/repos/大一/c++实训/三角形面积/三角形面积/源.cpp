//题目三十二：三角形面积
//【问题描述】
//给出三角形的三个边长为a，b，c，根据海伦公式来计算三角形的面积：
//s = (a + b + c) / 2；
//area = sqrt(s*(s - a)*(s - b)*(s - c));
//【要求】
//【数据输入】测试的数据有任意多组，每一组为一行。
//每一行为三角形的三个边长为a，b，c；
//【数据输出】输出每一个三角形的面积，两位小数。如果不是一个三角形，则输出错误提示信息：“Input error!”
//【样例输入】
//3 4 5
//6 8 10
//1 2 3
//【样例输出】
//6．00
//24．00
//Input error!
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	while (true)
	{
		double a[3];
		double s, area;
		for (int i = 0; i < 3; i++)
			cin >> a[i];
		for (int i = 0; i < 2; i++)
		{
			int k = i;
			for (int j = i + 1; j < 3; j++)
				if (a[k] < a[j])
				{
					k = j;
				}
			double temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
		if (a[0] < a[1] + a[2] && a[2]>a[0] - a[1])
		{
			s = (a[0] + a[1] + a[2]) / 2;
			area = sqrt(s*(s - a[0])*(s - a[1])*(s - a[2]));
			int c = (area * 100 + 0.5);
			cout <<fixed<<setprecision(2)<<c/100.0<< endl;
		}
		else
			cout << "Input error!" << endl;
	}
	system("pause");
	return 0;
}
