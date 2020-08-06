#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
struct place {                       
	string place_name;
	bool visit=false;
};
stack<string> way;              //存放当前路径
string str[20];                //存放最小路径（即最终输出的路径）
map<string, int> p_num;       //方便通过地点名查其下标
int dist[20][20];             //存放个节点之间距离
int n;                      //城市个数;
place p[20];                //存放地点名称和是否被访问
int min_sum=0xfffffff;      //初始化最小路程
void dfs(int star,int sum){
	if (sum >= min_sum)
		return;
	//如果栈满 且当前路径长度小于最小路径长 更新 存放最小路径的数组 str
	if (way.size() == n)
	{
		if (min_sum > sum)
		{
			min_sum = sum;
			int i = 0;
			while (way.empty() == 0)
			{
				str[i++] = way.top();
				way.pop();
			}
			for (int j = n-1; j >=0; j--)
				way.push(str[j]);
		}
		return;
	}
	//遍历剩余的为抵达地点 深搜
	for (int i = 0; i < n; i++)
	{
		if (i != star && p[i].visit == false)
		{
			p[i].visit = true;
			way.push(p[i].place_name);
			dfs(i, sum + dist[star][i]);
			way.pop();
			p[i].visit = false;
		}
	}
}
int main() {
	cout << "请输入城市个数：" << endl; cin >> n;
	//输入城市名称
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个城市" << endl;
		cin >> p[i].place_name;
		p_num.insert(pair<string, int>(p[i].place_name, i));
	}
	//初始化距离
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				if (dist[j][i] == 0)
				{
					if (dist[i][j] == 0)
					{
						cout << "请输入从" << p[i].place_name << "到" << p[j].place_name << "的距离" << endl;
						cin >> dist[i][j];
					}
				}
				else
					if (dist[i][j] == 0)
						dist[i][j] = dist[j][i];
		}
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << p[i].place_name << ' ' << p[j].place_name <<' '<<dist[i][j]<< endl;*/
	cout << "请输入出发城市" << endl;string p_star;cin >> p_star;
	int star = p_num[p_star];   //得到出发城市下标;

	//出发城市入栈后深搜
	p[star].visit = true;
	way.push(p[star].place_name);
	dfs(star,0);
	//输出
	cout << "最短路径如下：" << endl;
	for (int i = n-1; i >=0; i--)
		cout <<str[i] << ' ';
	cout <<endl;
	system("pause");
	return 0;
}