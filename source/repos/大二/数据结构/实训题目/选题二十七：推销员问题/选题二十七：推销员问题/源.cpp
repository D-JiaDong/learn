#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
struct place {                       
	string place_name;
	bool visit=false;
};
stack<string> way;              //��ŵ�ǰ·��
string str[20];                //�����С·���������������·����
map<string, int> p_num;       //����ͨ���ص��������±�
int dist[20][20];             //��Ÿ��ڵ�֮�����
int n;                      //���и���;
place p[20];                //��ŵص����ƺ��Ƿ񱻷���
int min_sum=0xfffffff;      //��ʼ����С·��
void dfs(int star,int sum){
	if (sum >= min_sum)
		return;
	//���ջ�� �ҵ�ǰ·������С����С·���� ���� �����С·�������� str
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
	//����ʣ���Ϊ�ִ�ص� ����
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
	cout << "��������и�����" << endl; cin >> n;
	//�����������
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "������" << endl;
		cin >> p[i].place_name;
		p_num.insert(pair<string, int>(p[i].place_name, i));
	}
	//��ʼ������
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				if (dist[j][i] == 0)
				{
					if (dist[i][j] == 0)
					{
						cout << "�������" << p[i].place_name << "��" << p[j].place_name << "�ľ���" << endl;
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
	cout << "�������������" << endl;string p_star;cin >> p_star;
	int star = p_num[p_star];   //�õ����������±�;

	//����������ջ������
	p[star].visit = true;
	way.push(p[star].place_name);
	dfs(star,0);
	//���
	cout << "���·�����£�" << endl;
	for (int i = n-1; i >=0; i--)
		cout <<str[i] << ' ';
	cout <<endl;
	system("pause");
	return 0;
}