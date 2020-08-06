//#include<iostream>
//using namespace std;
//int pe[20005][3];//pe[][0]:编号   pe[][1]:w[1]  
//                        //pe[][2]:d[i],c[i]
//int E[10];
//int n, k;
//void def(int pe[][3], int left, int right)
//{
//	if (left > right)
//		return;
//	int L = left, R = right;
//	int pivot = pe[(L + R) / 2][1];
//	int k = pe[(L + R) / 2][0];
//	int temp = (L + R) / 2;
//	while (R >= L)
//	{
//		/*for (int i = 0; i < n; i++)
//			cout <<pe[i][1]<<" ";
//		cout << endl;*/
//		while (R > temp&&pe[R][1] <= pivot)
//			R--;
//		while (R > temp)
//		{
//			pe[temp][1] = pe[R][1];
//			pe[temp][0] = pe[R][0];
//			temp = R;
//		}
//		while (L <temp&&pe[L][1] >=pivot)
//			L++;
//		while (L< temp)
//		{
//			pe[temp][1] = pe[L][1];
//			pe[temp][0] = pe[L][0];
//			temp = L;
//		}
//		if (R == L)
//		{
//			pe[temp][1] = pivot;
//			pe[temp][0] = k;
//			break;
//		}
//	}
//	def(pe, left, temp - 1);
//	def(pe, temp + 1, right);
//}
//void xuhao(int pe[][3])
//{
//	int p = pe[0][1], q = 0;
//	for (int i = 0; i <=n; i++)
//	{
//		if (pe[i][1] == p)
//			q++;
//		else
//		{
//			p = pe[i][1];
//			pe[i - q][2] = q;
//			q = 1;
//		}
//	}
//	/*for (int i = 0; i < n; i++)
//		cout << pe[i][2] << " " << ' ' << pe[i][0] << " " << pe[i][1] << endl;
//	cout << endl;*/
//	int i = 0;
//	p = pe[0][1];
//	q = pe[0][2];
//	while (i < n - 1)
//	{
//		if (pe[i][1] != p)
//		{
//			p = pe[i][1];
//			q = pe[i][2];
//		}
//		for (int j = i; j < i + q; j++)
//		{
//			int min = j;
//			for (int k = j; k < i + q; k++)
//				if (pe[min][0] > pe[k][0])
//					min = k;
//			int temp1 = pe[j][0], temp2 = pe[j][1];
//			pe[j][0] = pe[min][0]; pe[j][1] = pe[min][1];
//			pe[min][0] = temp1; pe[min][1] = temp2;
//		}
//		i += q;
//	}
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < 10; i++)
//		cin >> E[i];
//	for (int i = 0; i < n; i++)
//	{
//		pe[i][0] = i + 1;
//		cin >> pe[i][1];
//	}
//	/*for (int i = 0; i < n; i++)
//		cout << pe[i][2] << " " << ' ' << pe[i][0] << " " << pe[i][1] << endl;
//	cout << endl;*/
//	//权值快排
//	def(pe, 0, n - 1);
//	//序号排序
//	xuhao(pe);
//	//重新为权值赋值
//	for (int i = 0; i < n; i++)
//		pe[i][1] += E[i % 10];
//	//再次权值快排
//	def(pe, 0, n - 1);
//	//再次序号排序
//	xuhao(pe);
//	//cout << endl;
//	/*for (int i = 0; i < n; i++)
//		cout << pe[i][2] << " " << ' ' << pe[i][0]<<" " << pe[i][1] << endl;
//	cout << endl;*/
//	for (int i = 0; i < k; i++)
//		cout << pe[i][0] << ' ';
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
double sum, s, x;
int main()
{
	cin >> s >> x;
	double min = s - x, max = s + x;
	if (s < x)
		min = 0;
	if (min == 0 &&  7<=max)
	{
		cout << "y" << endl;
		return 0;
	}
	else
		if(min==0)
		{
			cout << "n" << endl;
			return 0;
		}
	double d = 7;
	sum += d;
	while (sum <= min)
	{
		d = (d / 100) * 98;
		sum += d;
	}
	if (sum > max)
		cout << "n" << endl;
	else
		if (sum <= max)
		{
			d = (d / 100) * 98;
			sum += d;
			if (sum >= max)
				cout << "n" << endl;
			else
				cout << "y" << endl;
		}
	system("pause");
	return 0;

}