#include<iostream>
using namespace std;
int N, M;
int piai[5002][2];
void qs(int piai[][2],int left,int right)
{
	if (left > right)
		return;
	int L = left, R = right;
	int pivot = piai[(L + R)/ 2][0];
	int k = piai[(L + R) / 2][1];
	int temp = (L + R) / 2;
	while (R >= L)
	{
		while (R > temp&&piai[R][0] >= pivot)
			R--;
		while (R > temp)
		{
			piai[temp][0] = piai[R][0];
			piai[temp][1] = piai[R][1];
			temp = R;
		}
		while (L < temp&&piai[L][0] <= pivot)
		{
			L++;
		}
		while (L < temp)
		{
			piai[temp][0] = piai[L][0];
			piai[temp][1] = piai[L][1];
			temp = L;
		}
		if (R == L)
		{
			piai[temp][0] = pivot;
			piai[temp][1] = k;
			break;
		}
	}
	qs(piai, left, temp - 1);
	qs(piai, temp + 1, right);

}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> piai[i][0] >> piai[i][1];
	qs(piai, 0, M - 1);
	for (int i = 0; i < M; i++)
		cout << piai[i][0] << piai[i][1] << endl;
	int sum = 0;
	int mosum = 0;
	for (int i = 0; i < M; i++)
	{
		if (sum + piai[i][1] < N)
		{
			sum += piai[i][1];
			mosum += piai[i][0] * piai[i][1];
		}
		else
		{
			mosum += piai[i][0] * (N - sum);
			break;
		}
	}
	cout << mosum << endl;
	system("pause");
	return 0;
}