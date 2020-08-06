#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define MaxInt 10000
const int MaxNumEdges = 50;
const int MaxNumVertices = 10;    //最大顶点个数
class Graph
{
private:
	int vNum;       //当前顶点个数
	int eNum;       //当前边数
	string Vertex[MaxNumVertices];     //顶点数组
	int Edge[MaxNumEdges][MaxNumVertices];      //边数组
	bool GetVertexPos(const string &vertex, int &i);  //给出顶点vertex在图中的位置
public:
	Graph(const int sz = MaxNumEdges);    //构造函数
	bool FindVertex(const string &vertex);
	bool InsertVertex(const string &vertex);     //插入一个顶点vertex
	bool InsertEdge(const string v1, const string v2, const int weight);    //插入一条边（v1，v2），该边上的权值为weight
	void Hospital();    //医院选址函数
};
bool Graph::GetVertexPos(const string & vertex, int & i)
{
	for (int k = 0; k < vNum; k++)
	{
		if (vertex == Vertex[k])
		{
			i = k;
			return true;
		}
	}
	return false;
}
Graph::Graph(const int sz) :vNum(0), eNum(0)     //构造函数
{
	int n, e;
	string name, tail, head;
	int weight;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
		{
			if (i == j)
				Edge[i][j] = 0;      //顶点到自身的权值为0
			else
				Edge[i][j] = 10000;   //邻接矩阵初始化为最大值
		}
	cout << "请输入顶点个数，最多输入10个！" << endl;
	cin >> n;
	cout << "请依次输入顶点名称：" << endl;
	for (int i = 0; i < n; i++)    //依次输入顶点，插入图中
	{
		cin >> name;
		InsertVertex(name);
		vNum++;
	}
	cout << "请输入边数：" << endl;
	cin >> e;
	cout << "输入边的信息：" << endl;
	for (int i = 0; i < e; i++)
	{
		cout << "请输入第" << i + 1 << "边的头顶点" << endl;
		cin >> head;
		cout << "请输入该边的尾顶点：" << endl;
		cin >> tail;
		cout << "请输入该边的权值：" << endl;
		cin >> weight;
		if (!InsertEdge(head, tail, weight))
		{
			cout << "该边不存在，请重新输入！" << endl;
			continue;
		}
	}
}
bool Graph::FindVertex(const string &vertex)   //给出顶点vertex在图中的位置
{
	for (int i = 0; i < vNum; i++)
		if (vertex == Vertex[i])
			return true;
	return false;
}
bool Graph::InsertVertex(const string &vertex)    //插入一个顶点vertex
{
	if (FindVertex(vertex))
		return false;
	Vertex[vNum] = vertex;
	return true;
}
bool Graph::InsertEdge(const string v1, const string v2, const int weight)    //插入一条边（v1，v2），该边上的权值为weight
{
	int k = 0, j = 0;
	if (GetVertexPos(v1, k) && GetVertexPos(v2, j))
	{
		Edge[k][j] = weight;
		eNum++;
		Edge[j][k] = weight;
		eNum++;
		return true;
	}
	else
		return false;
}
void Graph::Hospital()
{
	int i, j, k, m;
	for (k = 0; k < vNum; k++)      //求任意两顶点间的最短路径
		for (i = 0; i < vNum; i++)
			for (j = 0; j < vNum; j++)
				if (Edge[i][k] + Edge[k][j] < Edge[i][j])
					Edge[i][j] = Edge[i][k] + Edge[k][j];
	int min = MaxInt;     //设定机器最大数作村庄间距离之和的初值
	k = 0;     //k设医院的位置
	for (j = 0; j < vNum; j++)
	{
		m = 0;
		for (i = 0; i < vNum; i++)
			m = m + Edge[i][j];    //顶点到其他顶点最短距离的距离之和
		if (min > m)
		{
			min = m;
			k = j;
		}      //取顶点间的距离之和的最小值
	}
	cout << "各村离医院最近的医院选址，要建医院的村庄号：" << Vertex[k] << endl;;
	//输出要建医院的村庄号及离医院最远的村庄到医院的距离
	for (j = 0; j < vNum; j++)
		if (j != k)
			cout << "该村庄离" << j + 1 << "村庄最短距离为：" << Edge[k][j] << endl;
}
int main()
{
	Graph Town(MaxNumVertices);
	Town.Hospital();
	system("pause");
	return 0;
}