#include <iostream>
#include<iomanip>
using namespace std;
int a[40];
int n;
void swap(int c[],int x, int y)
{
	int temp = c[x];
	c[x] = c[y];
	c[y] = temp;
	/*int temp = c[x];
	for (int i = x; i > y; i--)
		c[i] = c[i-1];
	c[y] = temp;*/
}
void perm(int a[], int low, int high)
{
	if (low == high)
	{
		//当low==high时,此时list就是其中一个排列,输出list
		for (int i = 0; i <= low; i++)
			cout << setw(4) << a[i];
		cout << endl;
		
	}
	else
	{
		for (int i = low; i <=high; i++)
		{
			//每个元素与第一个元素交换
			swap(a,i, low);
			perm(a, low + 1, high); //交换后,得到子序列,用函数perm得到子序列的全排列
			//cout << a[i] << " " << a[low] << endl;
			swap(a,i, low);//最后,将元素交换回来,复原,然后交换另一个元素
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	perm(a, 0,n-1);
	system("pause");
	return 0;
}
