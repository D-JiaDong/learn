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
		//��low==highʱ,��ʱlist��������һ������,���list
		for (int i = 0; i <= low; i++)
			cout << setw(4) << a[i];
		cout << endl;
		
	}
	else
	{
		for (int i = low; i <=high; i++)
		{
			//ÿ��Ԫ�����һ��Ԫ�ؽ���
			swap(a,i, low);
			perm(a, low + 1, high); //������,�õ�������,�ú���perm�õ������е�ȫ����
			//cout << a[i] << " " << a[low] << endl;
			swap(a,i, low);//���,��Ԫ�ؽ�������,��ԭ,Ȼ�󽻻���һ��Ԫ��
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
