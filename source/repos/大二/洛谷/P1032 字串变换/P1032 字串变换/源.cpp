#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
string str_st,str_en;  //串 A B
string A[7], B[7];     //可转化形式
queue<string> que;     //存放待匹配字符串
queue<int> step;	   //与que队列对应 对应字符串所对应的匹配
map<string, int> mp;    //剪枝用 （字符串是否已经被匹配过)
int n;
int bfs() {
	bool bo = false;                                //得到最终串后退出循环的条件
	while (que.empty() == 0&&step.front()<10)      //队列不为空且步数小于10
	{
		if (mp[que.front()] == 1)                  //当前串被搜索过  出队
		{
			step.pop();
			que.pop();
			continue;
		}
		mp[que.front()] = 1;                       //标记被搜索的字符串
		for (int i = 0; i < n; i++)                //遍历转换方式
		{
			string str = que.front();              
			while (true)                           //循环到当前串中无当前需转换串
			{
				int place = str.find(A[i]);        //得到子串的位置
				if (place == -1)				  //没有子串 退出循环
				   	break;
				//获得转化后的新字符串 并将其入队
				string str_1 = que.front();        
				str_1.replace(place, A[i].size(), B[i]);
				que.push(str_1);
				//消除第一次出现的子串（将母串中的当前发现子串的第一个字母换成特殊符号）
				str[place] = '*';
				//新串步数入栈
				step.push(step.front() + 1);
				//是否退出循环
				if (str_1 == str_en)
				{
					bo = true;
					break;
				}
			}
			//是否退出循环
			if (bo)
				break;
		}
		//出队操作
		que.pop();
		step.pop();
		//返回步数队尾元素  即最小步数
		if (bo)
			return step.back();
	}
	return 0;
}
int main() {
	cin >> str_st >> str_en; 
	//第一个串及步数入队
	que.push(str_st);
	step.push(0);

	while (cin >> A[n] >> B[n]) n++;
	int ans = bfs();
	if (ans != 0)
		cout << ans << endl;
	else
		cout << "NO ANSWER!" << endl;
	system("pause");
	return 0;
}