#include<iostream>
using namespace std;
int sum;
struct child {
	int high;          //身高
	int index;         //下标
	int unhap_n=1;     //不高兴度
};
child ch[100];
int n;
int main()
{
	cin >> n;
	int max_ = n;          //记录当前应该安排的位置
	for (int i = 0; i < n; i++)
	{
		cin >> ch[i].high;
		ch[i].index = i;
	}
	while (1)
	{
		if (max_ <= 1)
			break;
		//找出未安排位置中最大身高
		child max_ch=ch[0];
		for (int i = 0; i < max_; i++)
		{
			if (ch[i].high >= max_ch.high)
				max_ch = ch[i];
		}
		//前移
		for (int i = max_ch.index+1; i < max_; i++)
		{
			//加不高兴度
			sum += ch[i].unhap_n;
			//cout << ch[i].unhap_n << endl;
			//改变小朋友对应下标 和不高兴度
			ch[i].index--;
			ch[i].unhap_n++;
			//前移
			ch[i-1]=ch[i];
		}
		//后移
		int j = max_ch.index + 1;
		for (j; j <max_;j++)
		{
			//加不确定度
			sum += max_ch.unhap_n;
			//cout <<"**"<<max_ch.unhap_n<< endl;
			//改变小朋友对应下标 和不高兴度
			max_ch.index++;
			max_ch.unhap_n++;
			//当前最大身高的小朋友移到当前需要安排的最末尾位置
			ch[max_ - 1] = max_ch;
		}
		max_--;//需要安排的最末尾位置前移
	}
	cout << sum << endl;
	system("pause");
	return 0;
}