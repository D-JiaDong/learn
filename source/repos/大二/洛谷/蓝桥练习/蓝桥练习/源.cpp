//第一题

//#include<iostream>
//using namespace std;
//int a[20][5];
//int sum = 0;
//int main()
//{
//	for(int i=0;i<20;i++)
//		for (int j = 0; j < 5; j++)
//		{
//			cin >> a[i][j];
//		}
//	for(int i1=0;i1<20;i1++)
//		for(int i2=0;i2<20;i2++)
//			for (int i3 = 0; i3 < 20; i3++)
//				for (int i4 = 0; i4 < 20; i4++)
//					for (int i5 = 0; i5 < 20; i5++)
//					{
//						if (i1 != i2 && i1 != i3 && i1 != i4 && i1 != i5 && i2 != i3 && i2 != i4 && i2 != i5 &&
//							i3 != i4 && i3 != i5 && i4 != i5)
//						{
//							if (a[i1][0] + a[i2][1] + a[i3][2] + a[i4][3] + a[i5][4] > sum)
//								sum = a[i1][0] + a[i2][1] + a[i3][2] + a[i4][3] + a[i5][4];
//						}
//					}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

//第二题

//#include<iostream>
//using namespace std;
//int main()
//{
//	int chu = 2019;
//	while (chu!=0)
//	{
//		cout <<chu % 26 <<endl;
//		chu = chu / 26;
//	}
//	system("pause");
//	return 0;
//}

//第三题

//#include<iostream>
//using namespace std;
//long long int a[20190326];
//int main()
//{
//	a[0] = 1; a[1] = 1; a[2] = 1;
//	for (int i = 3; i < 20190324; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
//		a[i] = a[i] % 10000;
//	}
//	cout << a[20190323] << endl;
//	system("pause");
//	return 0;
//}

//第四题

//#include<iostream>
//using namespace std;
//bool bo(int num)
//{
//	int a, b, c, d;
//	a = num % 10; num /= 10;
//	b = num % 10; num /= 10;
//	c = num % 10; num /= 10;
//	d = num % 10; num /= 10;
//	if (a == 2 || a == 4 || b == 2 || b == 4 || c == 2 || c == 4 || d == 2 || d == 4)
//		return false;
//	return true;
//}
//int main()
//{
//	int cou = 0;
//	for(int i=1;i<2019;i++)
//		for(int j=1;j<2019;j++)
//			for (int k = 1; k < 2019; k++)
//			{
//				if (i + j + k == 2019&&i!=j&&i!=k&&j!=k&&bo(i)&&bo(j)&&bo(k))
//				{
//					cou++;
//				}
//			}
//	cout << cou / 6 << endl;
//	system("pause");
//	return 0;
//}

//第五题

//#include<iostream>
//#include<queue>
//using namespace std;
//int d[4][2] = { 1,0,0,-1,0,1,-1,0 };//定义四个方向
//char d1[4] = { 'D','L','R','U' };//四个方向对应的字符
//int sum = 0xfffffff;//初始化路径最大化
//
//struct node
//{
//	char tf;
//	int x; int y;
//	int dir;
//	int cou;
//	int x1; int y1;
//	int visi;
//};
//node map[33][55];
//queue<node> way;
//bool bo(int x,int y)
//{
//	if (x<0||y<0||x>=30||x>=50||map[x][y].tf=='1'||map[x][y].visi==1)
//		return false;
//	return true;
//}
//void bfs()
//{
//	map[0][0].cou = 0;
//	map[0][0].dir = -1;
//	map[0][0].visi = 1;
//	way.push(map[0][0]);
//	while (!way.empty())
//	{
//		
//		bool boo = false;
//		for (int i = 0; i < 4; i++)
//		{
//			int x = way.front().x+d[i][0]; int y = way.front().y+d[i][1];
//			if (bo(x,y))
//			{
//				//改数据
//				map[x][y].dir = i;
//				map[x][y].x1 = way.front().x;
//				map[x][y].y1 = way.front().y;
//				map[x][y].visi = 1;
//				map[x][y].cou = way.front().cou + 1;
//				way.push(map[x][y]);
//			}
//			else
//				continue;
//			if (x == 29 && y == 49&&map[x][y].cou<sum)
//			{
//				boo = true;
//				char v[500];
//				int i = 0;
//				int X=map[x][y].x; int Y=map[x][y].y;
//				while (map[X][Y].dir != -1)
//				{
//					v[i++]=d1[map[X][Y].dir];
//					int M = map[X][Y].x1;
//					int N = map[X][Y].y1;
//					X = M; Y = N;
//				}
//				for (int j = i-1; j >=0; j--)
//				{
//					cout << v[j];
//				}
//				break;
//			}
//		}
//		if (boo)
//			break;
//		way.pop();
//	}
//}
//int main()
//{
//	for (int i = 0; i < 30; i++)
//		for (int j = 0; j < 50; j++)
//		{
//			map[i][j].x = i;
//			map[i][j].y = j;
//			cin >> map[i][j].tf;
//		}
//	bfs();
//	system("pause");
//	return 0;
//}

//第六题

//#include<iostream>
//using namespace std;
//int n;
//int sum;
// bool bo(int n)
//{
//	 
//	 while (n != 0)
//	 {
//		 int yu = n % 10;
//		 n =n/ 10;
//		 if (yu == 2 || yu == 0 || yu == 1 || yu == 9)
//			 return true;
//	 }
//	 return false;
//}
//int main()
//{
//	cin >> n;
//	int cou = 0;
//	while (n)
//	{
//		if (bo(n))
//		{
//			cout << n << endl;
//			sum += n;
//			cou++;
//		}
//		n--;
//	}
//	cout << sum <<' '<<cou<< endl;
//	system("pause");
//	return 0;
//}

//第七题

//#include<iostream>
//#include<queue>
//using namespace std;
//struct node
//{
//	int data;
//	int xb;
//};
//node a[100005];
//queue<node> no;
//int n;
//int deep;
//int mx;
//int ncm(int k)
//{
//	int sum = 1;
//	for (int i = 0; i < k-1; i++)
//	{
//		sum*= 2;
//	}
//	return sum;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i].data;
//		a[i].xb = i + 1;
//		no.push(a[i]);
//	}
//	int k = 1;
//	while (1)
//	{
//		int j = ncm(k);
//		cout << j << endl;
//		int sum = 0;
//		if (j <= n)
//		{
//			for (int i = 0; i <j; i++)
//			{
//				sum += no.front().data;
//				no.pop();
//			}
//			if (sum >mx)
//			{
//				deep = k;
//				mx = sum;
//			}
//
//		}
//		else
//		{
//			while (!no.empty())
//			{
//				sum += no.front().data;
//				no.pop();
//			}
//			if (sum > mx)
//				deep = k;
//			break;
//		}
//		k++;
//	}
//	cout << deep << endl;
//	system("pause");
//	return 0;
//}

//第八题

#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[1000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int mi=0xfffffff;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] < mi)
			mi = a[i + 1] - a[i];
	}
	cout << (a[n - 1] - a[0]) / mi + 1 << endl;
	system("pause");
	return 0;
}