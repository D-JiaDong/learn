#include<iostream>
#include<string>
using namespace std;
string num;
int main()
{
	int n;
	cin >> n;
	cin >> num;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < num.length(); j++)
			{
				if (j != 0)
					cout << ' ';
				cout << ' ';
				if (num[j] == '1' || num[j] == '4')
					for (int k = 0; k < n; k++)
						cout << ' ';
				else
					for (int k = 0; k < n; k++)
						cout << '-';
				cout << ' ';
			}
		}
		if (i == 1)
		{
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < num.length(); j++)
				{
					if (j != 0)
						cout << ' ';
					if (num[j] == '0' || num[j] == '4' || num[j] == '8' || num[j] == '9')
					{
						cout << '|';
						for (int k1 = 0; k1 < n; k1++)
							cout << ' ';
						cout << '|';
					}
					if (num[j] == '1' || num[j] == '2' || num[j] == '3' || num[j] == '7')
					{
						cout << ' ';
						for (int k1 = 0; k1 < n; k1++)
							cout << ' ';
						cout << '|';
					}
					if (num[j] == '5' || num[j] == '6')
					{
						cout<< '|';
						for(int k1 = 0; k1 < n; k1++)
							cout <<' ';
						cout<< ' '; 
					}
				}
				if (k != n - 1)
					cout << endl;
			}
		}
		if (i == 2) 
		{
			for (int j = 0; j < num.length(); j++)
			{
				if (j != 0)
					cout << ' ';
				cout << ' ';
				if (num[j] == '0' || num[j] == '1'||num[j]=='7')
					for (int k = 0; k < n; k++)
						cout << ' ';
				else
					for (int k = 0; k < n; k++)
						cout << '-';
				cout << ' ';
			}
		}
		if (i == 3)
		{
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < num.length(); j++)
				{
					if (j != 0)
						cout << ' ';
					if (num[j] == '0' || num[j] == '6' || num[j] == '8')
					{
						cout << '|';
						for (int k1 = 0; k1 < n; k1++)
							cout << ' ';
						cout << '|';
					}
					if (num[j] == '1' ||  num[j] == '3' || num[j] == '4' || num[j] == '5' || num[j] == '7' || num[j] == '9')
					{
						cout << ' ';
						for (int k1 = 0; k1 < n; k1++)
							cout << ' ';
						cout << '|';
					}
					if (num[j] == '2')
					{
						cout << '|';
						for (int k1 = 0; k1 < n; k1++)
							cout << ' ';
						cout << ' ';
					}
				}
				if (k != n - 1)
					cout << endl;
			}
		}
		if (i == 4)
		{
			for (int j = 0; j < num.length(); j++)
			{
				if (j != 0)
					cout << ' ';
				cout << ' ';
				if (num[j] == '0' || num[j] == '2' || num[j] == '3' || num[j] == '5' || num[j] == '6'||num[j] == '8' || num[j] == '9' )
					for (int k = 0; k < n; k++)
						cout << '-';
				else
					for (int k = 0; k < n; k++)
						cout << ' ';
				cout << ' ';
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}