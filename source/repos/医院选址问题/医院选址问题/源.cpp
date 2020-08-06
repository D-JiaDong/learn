#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define MaxInt 10000
const int MaxNumEdges = 50;
const int MaxNumVertices = 10;    //��󶥵����
class Graph
{
private:
	int vNum;       //��ǰ�������
	int eNum;       //��ǰ����
	string Vertex[MaxNumVertices];     //��������
	int Edge[MaxNumEdges][MaxNumVertices];      //������
	bool GetVertexPos(const string &vertex, int &i);  //��������vertex��ͼ�е�λ��
public:
	Graph(const int sz = MaxNumEdges);    //���캯��
	bool FindVertex(const string &vertex);
	bool InsertVertex(const string &vertex);     //����һ������vertex
	bool InsertEdge(const string v1, const string v2, const int weight);    //����һ���ߣ�v1��v2�����ñ��ϵ�ȨֵΪweight
	void Hospital();    //ҽԺѡַ����
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
Graph::Graph(const int sz) :vNum(0), eNum(0)     //���캯��
{
	int n, e;
	string name, tail, head;
	int weight;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
		{
			if (i == j)
				Edge[i][j] = 0;      //���㵽�����ȨֵΪ0
			else
				Edge[i][j] = 10000;   //�ڽӾ����ʼ��Ϊ���ֵ
		}
	cout << "�����붥��������������10����" << endl;
	cin >> n;
	cout << "���������붥�����ƣ�" << endl;
	for (int i = 0; i < n; i++)    //�������붥�㣬����ͼ��
	{
		cin >> name;
		InsertVertex(name);
		vNum++;
	}
	cout << "�����������" << endl;
	cin >> e;
	cout << "����ߵ���Ϣ��" << endl;
	for (int i = 0; i < e; i++)
	{
		cout << "�������" << i + 1 << "�ߵ�ͷ����" << endl;
		cin >> head;
		cout << "������ñߵ�β���㣺" << endl;
		cin >> tail;
		cout << "������ñߵ�Ȩֵ��" << endl;
		cin >> weight;
		if (!InsertEdge(head, tail, weight))
		{
			cout << "�ñ߲����ڣ����������룡" << endl;
			continue;
		}
	}
}
bool Graph::FindVertex(const string &vertex)   //��������vertex��ͼ�е�λ��
{
	for (int i = 0; i < vNum; i++)
		if (vertex == Vertex[i])
			return true;
	return false;
}
bool Graph::InsertVertex(const string &vertex)    //����һ������vertex
{
	if (FindVertex(vertex))
		return false;
	Vertex[vNum] = vertex;
	return true;
}
bool Graph::InsertEdge(const string v1, const string v2, const int weight)    //����һ���ߣ�v1��v2�����ñ��ϵ�ȨֵΪweight
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
	for (k = 0; k < vNum; k++)      //�����������������·��
		for (i = 0; i < vNum; i++)
			for (j = 0; j < vNum; j++)
				if (Edge[i][k] + Edge[k][j] < Edge[i][j])
					Edge[i][j] = Edge[i][k] + Edge[k][j];
	int min = MaxInt;     //�趨�������������ׯ�����֮�͵ĳ�ֵ
	k = 0;     //k��ҽԺ��λ��
	for (j = 0; j < vNum; j++)
	{
		m = 0;
		for (i = 0; i < vNum; i++)
			m = m + Edge[i][j];    //���㵽����������̾���ľ���֮��
		if (min > m)
		{
			min = m;
			k = j;
		}      //ȡ�����ľ���֮�͵���Сֵ
	}
	cout << "������ҽԺ�����ҽԺѡַ��Ҫ��ҽԺ�Ĵ�ׯ�ţ�" << Vertex[k] << endl;;
	//���Ҫ��ҽԺ�Ĵ�ׯ�ż���ҽԺ��Զ�Ĵ�ׯ��ҽԺ�ľ���
	for (j = 0; j < vNum; j++)
		if (j != k)
			cout << "�ô�ׯ��" << j + 1 << "��ׯ��̾���Ϊ��" << Edge[k][j] << endl;
}
int main()
{
	Graph Town(MaxNumVertices);
	Town.Hospital();
	system("pause");
	return 0;
}