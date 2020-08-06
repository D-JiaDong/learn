#include <iostream>
using namespace std;
int arr[20][2];
void zuhe(int x, int k, int m,int n,int arr[][2] )//数组，下标，标记个数，最大标记个数，元素个数
{
	if (k == n)
	{
		for (int i = 0; i < m; i++)
			if (arr[i][1]== 1)
				cout << arr[i][0] << " ";
		cout << endl;
		return;
	}
	if (x == m)return;
	if (arr[x][1] == 0)
	{
		arr[x][1] = 1;
		zuhe(x + 1, k + 1, m, n,arr);
		arr[x][1] = 0;
	}
	cout << endl;
	zuhe(x + 1, k, m, n,arr);
}
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		arr[i][0] = i + 1;
	zuhe(0, 0, m, n,arr);
	system("pause");

	return 0; return 0;
}
//void dfs(int pos, int cnt, int n, int k, int a[], bool visited[]) {
//	//已标记了k个数，输出结果
//	if (cnt == k) {
//		for (int i = 0; i < n; i++)
//			if (visited[i]) cout << a[i] << ' ';
//		cout << endl;
//		return;
//	}cout << endl;
//		return;
//	}cout << endl;
//		return;
//	//处理到最后一个数，直接返回
//处理到最后一个数，直接返回
//	if (pos == n) return;
//
//	//如果a[pos]没有被选中
//	if (!visited[pos]) {
//		//选中a[pos]
//		visited[pos] = true;
//		//处理在子串a[pos+1, n-1]中取出k-1个数的子问题
//		dfs(pos + 1, cnt + 1, n, k, a, visited);
//		//回溯
//		visited[pos] = false;
//	}
//	//处理在子串a[pos+1, n-1]中取出k个数的问题
//	//dfs(pos + 1, cnt, n, k, a, visited);
//}
//int main() {
//	int i, n, k;
//	while (cin >> n >> k, n || k)
//	{
//		int *a = new int[n];
//		bool *visited = new bool[n];
//		for (i = 0; i < n; i++)
//		{
//			a[i] = i + 1;
//			visited[i] = false;
//		}
//		dfs(0, 0, n, k, a, visited);
//		delete[] a;
//		delete[] visited;
//	}
//	getchar();
//	return 0;
//}