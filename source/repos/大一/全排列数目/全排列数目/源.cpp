#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void perm(int list[], int low, int high, int &m)
{
	int i;
	if (low == high)
	{
		if (list[0] != list[1] + 1 && list[0] != list[1] - 1 &&
			list[0] != list[3] + 1 && list[0] != list[3] - 1 &&
			list[0] != list[4] + 1 && list[0] != list[4] - 1 &&
			list[0] != list[5] + 1 && list[0] != list[5] - 1 &&
			list[1] != list[2] + 1 && list[1] != list[2] - 1 &&
			list[1] != list[4] + 1 && list[1] != list[4] - 1 &&
			list[1] != list[5] + 1 && list[1] != list[5] - 1 &&
			list[1] != list[6] + 1 && list[1] != list[6] - 1 &&
			list[2] != list[5] + 1 && list[2] != list[5] - 1 &&
			list[2] != list[6] + 1 && list[2] != list[6] - 1 &&
			list[3] != list[4] + 1 && list[3] != list[4] - 1 &&
			list[3] != list[7] + 1 && list[3] != list[7] - 1 &&
			list[3] != list[8] + 1 && list[3] != list[8] - 1 &&
			list[4] != list[5] + 1 && list[4] != list[5] - 1 &&
			list[4] != list[7] + 1 && list[4] != list[7] - 1 &&
			list[4] != list[8] + 1 && list[4] != list[8] - 1 &&
			list[4] != list[9] + 1 && list[4] != list[9] - 1 &&
			list[5] != list[6] + 1 && list[5] != list[6] - 1 &&
			list[5] != list[8] + 1 && list[5] != list[8] - 1 &&
			list[5] != list[9] + 1 && list[5] != list[9] - 1 &&
			list[6] != list[9] + 1 && list[6] != list[9] - 1 &&
			list[7] != list[8] + 1 && list[7] != list[8] - 1 &&
			list[8] != list[9] + 1 && list[8] != list[9] - 1
			)
		{
			for (i = 0; i <= low; i++)
				cout << list[i];
			cout << endl;


			m++;
		}
		//当low==high时,此时list就是其中一个排列,输出list

	}
	else
	{
		for (int i = low; i <= high; i++)
		{
			//每个元素与第一个元素交换
			swap(list[i], list[low]);
			perm(list, low + 1, high, m); //交换后,得到子序列,用函数perm得到子序列的全排列
			swap(list[i], list[low]);//最后,将元素交换回来,复原,然后交换另一个元素
		}
	}
}
int main()
{
	int a = 0;
	int list[] = { 0,1,2,3 ,4,5,6,7,8,9 };
	perm(list, 0, 9, a);
	cout << a << endl;
	system("pause");
	return 0;
}
