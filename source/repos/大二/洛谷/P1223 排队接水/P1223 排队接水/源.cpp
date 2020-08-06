#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class pep {
public:
	double ser;
	double ti;
};
int N; pep p[1003];
bool cmp(pep p1,pep p2 )
{
	return p1.ti < p2.ti;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].ti;
		p[i].ser = i + 1;
	}
	sort(p, p + N, cmp);
	/*for (int i = 0; i < N; i++)
		cout << p[i].ser << "  " << p[i].ti << endl;*/
	double sum=0;
	for (int i = 0; i <N-1; i++)
	{
		cout << p[i].ser<<' ';
		sum += (N - i - 1)*p[i].ti;
	}
	cout << p[N - 1].ser << endl;
	double avet = sum / N;
	cout <<fixed<<setprecision(2)<<avet << endl;
	system("pause");
	return 0;
}