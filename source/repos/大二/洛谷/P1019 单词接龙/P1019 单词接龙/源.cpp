#include<iostream>
#include<string>
using namespace std;
int n;
int SUM_len;
string words[21];
int visit[21];
int repetition(int i,int x)
{
	for (int j = words[x].length() - 1; j >= 0; j--)
	{
		bool bo = true;
		if (words[x][j] == words[i][0])
		{
			int k_x = j + 1;
			int k_i = 1;
			while (k_x < words[x].length())
			{
				if (words[x][k_x] == words[i][k_i])
				{
					k_x++; k_i++;
					continue;
				}
				else
				{
					bo = false;
					break;
				}
			}
		}
		else
			continue;
		if (bo)
			return words[x].length()-j;
	}
	return 0;
}
void dfs(int x,int LEN)
{
	//cout << words[x]<<' ';
	visit[x]++;
	bool end = true;
	for (int i = 0; i < n; i++)
	{
		int rep = repetition(i, x);
		if (rep&& visit[i] < 2)
		{
			dfs(i, LEN + words[i].length() - rep);
			end = false;
		}
	}
	if (end)
	{
		SUM_len = SUM_len > LEN ? SUM_len : LEN;
		//cout << SUM_len << endl;
		/*if (SUM_len < LEN)
			cout << endl;*/
	}
	visit[x]--;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> words[i];
	//cout << words[0].length() << endl;
	char star;
	cin >> star;
	for (int i = 0; i < n; i++)
	{
		if (words[i][0] == star)
			dfs(i, words[i].length());
	}
	cout << SUM_len << endl;
	system("pause");
	return 0;
}