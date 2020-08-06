#include<iostream>
#include<string>
using namespace std;
string num[30];
int n;
int main()
{
	cin >> n;
	int i = 0; int j = 0; int k = 0;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			int count = 0; int count1 = 0;
			int lon = (num[k].length()> num[j].length()) ? num[j].length() : num[k].length();
			for (int u = 0; u < lon; u++)
			{
				if (num[k][u] != num[j][u])
				{
					count1 = 1;
					if (num[k][u] < num[j][u])
					{
						count = 1;
						break;
					}
					else
						break;
				}
			}
			int K = num[k].length(); int J = num[j].length();
			if ( count1 == 0 &&((K>J&&num[k][J]<num[j][0]) || (K<J&&num[k][0]<num[j][K])) )
				count = 1;
			if (count == 1)
				k = j;
		}
		string temp = num[i];
		num[i] = num[k];
		num[k] = temp;
	}
	for (int i = 0; i < n; i++)
		cout << num[i];
	system("pause");
	return 0;
}