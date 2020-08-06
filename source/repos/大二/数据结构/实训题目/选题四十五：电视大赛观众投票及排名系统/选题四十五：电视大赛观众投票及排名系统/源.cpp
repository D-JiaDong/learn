#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	string name; /*选手姓名*/
	int num;  /*选手编号*/
	int score=0;  /*选手得分*/
	int tax;  /*选手名次*/
};
node  user[10];
int n;
bool cmp(node a,node b)
{
	return a.score > b.score;
}
int main() {
	cout << "输入选手人数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "输入第" << i + 1 << "位选手姓名" << endl;
		cin >> user[i].name;
		user[i].num = i + 1;
	}
	cout << "开始投票" << endl;
	while (1)
	{
		int i;
		cin >> i;
		if (i == 0)
			break;
		else
			user[i - 1].score++;
	}
	sort(user, user + n, cmp);
	int ta = 1;               //存放当前名次
	int sor = user[0].score;  //当前最小得票数
	//从高到低遍历选手   给选手排名
	for (int i = 0; i < n; i++)
	{
		if (user[i].score == sor)
			user[i].tax = ta;
		else
		{
			ta++;
			sor = user[i].score;
			user[i].tax = i+1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (user[i].tax == 1)
		{
			cout << "冠军：" << '\t' << user[i].name << '\t' << "票数：" << user[i].score << endl;
			continue;
		}
		if(user[i].tax==2)
		{
			cout << "亚军：" << '\t' << user[i].name << '\t' << "票数：" << user[i].score << endl;
			continue;
		}
		if (user[i].tax == 3)
		{
			cout << "季军：" << '\t' << user[i].name << '\t' << "票数：" << user[i].score << endl;
			continue;
		}
		cout<<"第"<<i+1<<"名"<<'\t'<<user[i].name<<'\t' << "票数：" << user[i].score << endl;
	}
	system("pause");
	return 0;
}