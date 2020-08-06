#include<iostream>
using namespace std;
int coun = 0;
void df(int bu,int step)
{
	if (step > 39)
		return;
	if (step == 39 && bu % 2 == 0)
	{
		coun++;
		return;
	}
	else
	{
		df(bu + 1, step + 1);
		df(bu + 1, step + 2);
	}
}
int main()
{
	df(0, 0);
	cout<< coun;
	system("pause"); 
	return 0;
}