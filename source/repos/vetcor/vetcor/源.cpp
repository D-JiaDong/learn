#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main() {	
	vector<int> a;
	vector<int>::iterator p;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	sort(a.begin(), a.end(),cmp);
	//while (a.size() != 0)
	//{
	//	//int c = a.back();
	//	cout << a.back()<< endl;
	//	a.pop_back();
	//}
	cout << a.back() << endl;
	p  = a.end()-1;
	cout <<*p<< endl;
	//a.erase(a.begin(),a.begin()+2);//a.erase(a,b) ɾ���ӵ�a��Ԫ�ص���b��Ԫ��   ��ǰ������
	cout << endl;
	while (a.size() != 0)
	{
		//int c = a.back();
		cout << a.back() << endl;
		a.pop_back();
	}
	string str = "abcdefg";
	string st = "bcd";
	cout << str.find(st) << endl;
	system("pause");
	return 0;
}