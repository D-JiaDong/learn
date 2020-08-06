#include<iostream>
using namespace std;
char arr[110];
int p1, p2, p3;
int main()
{
	cin >> p1 >> p2 >> p3;
	cin >> arr;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] != '-')
			cout << arr[i];
		else
		{
			if (arr[i - 1] >= arr[i + 1])
				cout << arr[i];
			else
			{
				if (arr[i + 1] - arr[i - 1] == 1)
					continue;
				else
				{
					if (((arr[i - 1] >= 65 && arr[i - 1] <= 90) && (arr[i + 1] >= 65 && arr[i + 1] <= 90)) ||
						(arr[i - 1] >= 97 && arr[i - 1] <= 122) && (arr[i + 1] >= 97 && arr[i + 1] <= 122) ||
						(arr[i - 1] >= 48 && arr[i - 1] <= 57) && (arr[i + 1] >= 48 && arr[i + 1] <= 57))
					{
						if (p3 == 1)
						{
							if (p1 == 1)
								for (int j = 1; j < arr[i + 1] - arr[i - 1]; j++)
									for (int j1 = 0; j1 < p2; j1++)
									{
										if (arr[i + 1] >= 65 && arr[i + 1] <= 90)
											cout << char(arr[i - 1] + j + 32);
										else
											cout << char(arr[i - 1] + j);

									}
							else
							{
								if (p1 == 2)
									for (int k = 1; k < arr[i + 1] - arr[i - 1]; k++)
										for (int k1 = 0; k1 < p2; k1++)
										{
											if (arr[i + 1] >= 97 && arr[i + 1] <= 122)
												cout << char(arr[i - 1] + k - 32);
											else cout << char(arr[i - 1] + k);
										}
								else
									for (int n = 1; n < arr[i + 1] - arr[i - 1]; n++)
										for (int n1 = 0; n1 < p2; n1++)
											cout << '*';
							}
						}
						else
						{
							if (p3 == 2)
								if (p1 == 1)
									for (int j = 1; j < arr[i + 1] - arr[i - 1]; j++)
										for (int j1 = 0; j1 < p2; j1++)
										{
											if (arr[i + 1] >= 65 && arr[i + 1] <= 90)
												cout << char(arr[i + 1] - j + 32);
											else
												cout << char(arr[i + 1] - j);
										}
								else
								{
									if (p1 == 2)
										for (int k = 1; k < arr[i + 1] - arr[i - 1]; k++)
											for (int k1 = 0; k1 < p2; k1++)
											{
												if (arr[i + 1] >= 97 && arr[i + 1] <= 122)
													cout << char(arr[i + 1] - k - 32);
												else cout << char(arr[i + 1] - k);
											}
									else
										for (int n = 1; n < arr[i + 1] - arr[i - 1]; n++)
											for (int n1 = 0; n1 < p2; n1++)
												cout << '*';
								}
						}
					}
					else
						cout << arr[i];
				}
			}
		}
	}
	system("pause");
	return 0;
}
