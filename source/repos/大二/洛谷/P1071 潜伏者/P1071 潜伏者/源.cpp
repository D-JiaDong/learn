#include<iostream>
#include<string>
using namespace std;
string encryption;
string unencryption;
string translate;
char rules[26];
int main()
{
	cin >> encryption;
	cin >> unencryption;
	cin >> translate;
	for (int i = 0; i < encryption.length(); i++)
		if (rules[encryption[i] - 65] != '\0')
		{
			if (rules[encryption[i] - 65] != unencryption[i])
			{
				cout << "Failed" << endl;
				system("pause");
				return 0;
			}
		}
		else
			rules[encryption[i] - 65] = unencryption[i];
	for(int i=0;i<26;i++)
		if (rules[i] == '\0')
		{
			cout << "Failed" << endl;
			system("pause");
			return 0;
		}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if (j != i && rules[i] == rules[j])
			{
				cout << "Failed" << endl;
				system("pause");
				return 0;
			}
	for (int i = 0; i < translate.length(); i++)
		cout << rules[translate[i] - 65];
	system("pause");
	return 0;
}