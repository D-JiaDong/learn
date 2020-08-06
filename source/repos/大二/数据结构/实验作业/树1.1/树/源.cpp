#include<iostream>
#include<queue>
using namespace std;
char pred[9] = { 'a','b','h','f','d','e','c','k','g' };//先序
char eplg[9] = { 'h','b','d','f','a','e','k','c','g' };//中序
int n = 9;
void df(int cur, int l, int r, int lorr, int ceng)
//先序点下标cur，该先序点的子树所在中序的范围（左边界l  右边界r）,
//左右子树lorr(0.1判断)  该先序点层数
{
	if (l == r)
	{
		for (int j = 0; j < ceng; j++)
			cout << '\t';
		cout << '(' << lorr << ')' << pred[cur] << endl;
	}
	//当该先序点为叶子节点时 输出
	if (cur >= n || l >= r)
		return;
	for (int j = 0; j < ceng; j++)
		cout << '\t';
	if (cur != 0)
		cout << '(' << lorr << ')' << pred[cur] << endl;
	else
		cout<< pred[cur] << endl;
	int i;
	for (i = l; i <= r; i++)
	{
		if (eplg[i] == pred[cur])
		{
			break;
		}
	}
	//遍历中序 查找该先序点结点下标 
	df(cur + 1, l, i - 1, 0, ceng + 1);          //该先序点左孩子深搜
	df(cur + (i - l + 1), i + 1, r, 1, ceng + 1);//该先序点右孩子深搜
}
int  main()
{
	df(0, 0, n - 1, 0, 0);
	system("pause");
	return 0;
}



