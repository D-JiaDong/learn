#include<iostream>
#include<algorithm>  
#include<iomanip>
using namespace std;
class A
{
public:
	int data[3];
};
A a[200004];
A b[100002]; int x; 
A c[100002]; int y;
bool cmp(A a, A b)
{
	if (a.data[1] == b.data[1])
		return a.data[2] < b.data[2];
	return a.data[1] > b.data[1];
}
void merge(A a[], A b[],A c[],int x,int y)
{
	int n=0;
	int i = 0,j = 0;
	while (1)
	{
		//cout << i << ' ' << j << ' ' << n << endl;
		if (i >=x)
		{
			while (n <x + y)
			{
				for (int v = 0; v < 3; v++)
					a[n].data[v] = c[j].data[v];
				n++; j++;
			}
			break;
		}
		if (j >=y)
		{
			//cout << j << y << endl;
			while (n <x + y)
			{
				for (int v = 0; v < 3; v++)
					a[n].data[v] = b[i].data[v];
				n++; i++;
			}
			break;
		}
		if (b[i].data[1] > c[j].data[1] || (b[i].data[1] == c[j].data[1] && b[i].data[2] < c[j].data[2]))
		{
			for (int v = 0; v < 3; v++)
				a[n].data[v] = b[i].data[v];
			n++; i++;
		}
		else
		{
			for (int v = 0; v < 3; v++)
				a[n].data[v] = c[j].data[v];
			n++; j++;
		}
	}
}
int main()
{
	int N, R, Q;
	cin >> N >> R >> Q;
	N *= 2;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].data[1];
		a[i].data[2] = i + 1;
	}
	for (int i = 0; i < N; i++)
		cin >> a[i].data[0];
	for (int i = 0; i < N; i++)
		cout << a[i].data[2] << ":" << a[i].data[1] << endl;
	cout << endl;
	sort(a , a  + N, cmp);
	for (int i = 0; i < N; i++)
		cout << a[i].data[2] << ":" << a[i].data[1] << endl;
	cout << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < N; j += 2)
		{
			if (a[j].data[0] > a[j + 1].data[0])
			{
				a[j].data[1]++;
				for (int v = 0; v < 3; v++)
				{
					b[x].data[v] = a[j].data[v];
					c[y].data[v] = a[j + 1].data[v];
				}
				x++; y++;
			}
			else
			{
				a[j + 1].data[1]++;
				for (int v = 0; v < 3; v++)
				{
					b[x].data[v] = a[j+1].data[v];
					c[y].data[v] = a[j].data[v];
				}
				x++; y++;
			}
		}
		merge(a, b, c, x, y);
		/*cout << x << y << endl;
		for (int m = 0; m < x; m++)
			cout << b[m][0] << ' ' << b[m][1] << " " << b[m][2] << endl;
		cout << endl;*/
		/*for (int m = 0; m < y; m++)
			cout << c[m][0] << ' ' << c[m][1] << " " << c[m][2] << endl;
		cout << endl;*/
		/*for (int i = 0; i < N; i++)
			cout << a[i][2] << ":" << a[i][1] << endl;
		cout << endl;*/
		x = 0; y = 0;
	}
	/*for (int i = 0; i <  N; i++)
		cout << a[i][2] << ":" << a[i][1] << endl;
	cout << endl;*/
	cout << a[Q - 1].data[2] << endl;
	system("pause");
	return 0;
}