#include<iostream>
using namespace std;
int main() {
	int num1 = 15;
	int num2 = 19;
	int sum = 0;
	for (int i = num1; i <= num2; i++)
	{
		bool bo = true;
		int i_ = i;
		while (bo)
		{
			int yu = i_ % 10;
			cout<< yu << endl;
			sum += yu;
			i_ = i_ / 10;
			if (i_ == 0) {
				bo = false;
			}
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}