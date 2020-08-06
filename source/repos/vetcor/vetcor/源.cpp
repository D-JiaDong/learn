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
	//a.erase(a.begin(),a.begin()+2);//a.erase(a,b) 删除从第a个元素到第b个元素   包前不包后
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