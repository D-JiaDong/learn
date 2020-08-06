#include<iostream>
#include<stack>
using namespace std;
struct root
{
	int nod;     //存储结点序号
	int chil[5]; //存储各邻接结点序号
	int chil_n;  //该节点邻接结点个数
};
bool bo[2] = { false,false };
stack<root> way;  
root Ro[15];    //存储结点
int visi[15];   //判断结点是对否走过

//录入图信息
void shuju()
{
	for (int i = 0; i < 15; i++)
		Ro[i].nod = i;
	Ro[0].chil_n = 4; Ro[0].chil[0] = 1; Ro[0].chil[1] = 2; Ro[0].chil[2] = 3; Ro[0].chil[3] = 4;
	Ro[1].chil_n = 3; Ro[1].chil[0] = 0; Ro[1].chil[1] = 6; Ro[1].chil[2] = 8;
	Ro[2].chil_n = 0;
	Ro[3].chil_n = 1; Ro[3].chil[0] = 6;
	Ro[4].chil_n = 1; Ro[4].chil[0] = 7;
	Ro[5].chil_n = 2; Ro[5].chil[0] = 8; Ro[5].chil[1] = 9;
	Ro[6].chil_n = 4; Ro[6].chil[0] = 1; Ro[6].chil[1] = 3; Ro[6].chil[2] = 7; Ro[6].chil[3] = 9;
	Ro[7].chil_n = 4; Ro[7].chil[0] = 4; Ro[7].chil[1] = 6; Ro[7].chil[2] = 10; Ro[7].chil[3] = 11;
	Ro[8].chil_n = 3; Ro[8].chil[0] = 1; Ro[8].chil[1] = 5; Ro[8].chil[2] = 12;
	Ro[9].chil_n = 4; Ro[9].chil[0] = 5; Ro[9].chil[1] = 6; Ro[9].chil[2] = 10; Ro[9].chil[3] = 12;
	Ro[10].chil_n = 3; Ro[10].chil[0] = 7; Ro[10].chil[1] = 9; Ro[10].chil[2] = 13;
	Ro[11].chil_n = 2; Ro[11].chil[0] = 7; Ro[11].chil[1] = 13;
	Ro[12].chil_n = 3; Ro[12].chil[0] = 8; Ro[12].chil[1] = 9; Ro[12].chil[2] = 14;
	Ro[13].chil_n = 3; Ro[13].chil[0] = 10; Ro[13].chil[1] = 11; Ro[13].chil[2] = 14;
	Ro[14].chil_n = 2; Ro[14].chil[0] = 12; Ro[14].chil[1] = 13;
}
//深度优先搜索
void dfs(int node)
{
	//cout<<node<<endl;
	//结点1，5不可行  走过的结点不可行
	if (node == 1 || node == 5 || visi[node] == 1)
		return;
	//如果结点十五入栈 且结点6，10都在栈内  则形成完整路径 将栈内结点输出
	if (node == 14 && bo[0] == true && bo[1] == true)
	{
		//cout<<"*****"<<endl;
		//cout<<bo[0]<<bo[1]<<endl;
		root way1[30];
		int i = 0;
		while (!way.empty())
		{
			way1[i++] = way.top();
			way.pop();
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << way1[j].nod << ' ';
			way.push(way1[j]);
		}
		cout << 14 << endl;
		return;
	}
	
	visi[node] = 1;
	
	//两个布尔类型变量 判断6，10是都入栈
	if (node == 6)
		bo[0] = true;
	if (node == 10)
		bo[1] = true;

	way.push(Ro[node]);
	
	//遍历邻接结点
	for (int i = 0; i < Ro[node].chil_n; i++)
		dfs(Ro[node].chil[i]);
	
	visi[node] = 0;
	
	if (node == 6)
		bo[0] = false;
	if (node == 10)
		bo[1] = false;
	
	way.pop();
}
int main()
{
	shuju();
	dfs(0);
	system("pause");
	return 0;
}