#include <iostream>
using namespace std;
int arr[20][2];
void zuhe(int x, int k, int m,int n,int arr[][2] )//���飬�±꣬��Ǹ���������Ǹ�����Ԫ�ظ���
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
//	//�ѱ����k������������
//	if (cnt == k) {
//		for (int i = 0; i < n; i++)
//			if (visited[i]) cout << a[i] << ' ';
//		cout << endl;
//		return;
//	}cout << endl;
//		return;
//	}cout << endl;
//		return;
//	//�������һ������ֱ�ӷ���
//�������һ������ֱ�ӷ���
//	if (pos == n) return;
//
//	//���a[pos]û�б�ѡ��
//	if (!visited[pos]) {
//		//ѡ��a[pos]
//		visited[pos] = true;
//		//�������Ӵ�a[pos+1, n-1]��ȡ��k-1������������
//		dfs(pos + 1, cnt + 1, n, k, a, visited);
//		//����
//		visited[pos] = false;
//	}
//	//�������Ӵ�a[pos+1, n-1]��ȡ��k����������
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