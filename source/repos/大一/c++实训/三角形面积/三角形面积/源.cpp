//��Ŀ��ʮ�������������
//������������
//���������ε������߳�Ϊa��b��c�����ݺ��׹�ʽ�����������ε������
//s = (a + b + c) / 2��
//area = sqrt(s*(s - a)*(s - b)*(s - c));
//��Ҫ��
//���������롿���Ե�������������飬ÿһ��Ϊһ�С�
//ÿһ��Ϊ�����ε������߳�Ϊa��b��c��
//��������������ÿһ�������ε��������λС�����������һ�������Σ������������ʾ��Ϣ����Input error!��
//���������롿
//3 4 5
//6 8 10
//1 2 3
//�����������
//6��00
//24��00
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
