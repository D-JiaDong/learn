#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
string str_st,str_en;  //�� A B
string A[7], B[7];     //��ת����ʽ
queue<string> que;     //��Ŵ�ƥ���ַ���
queue<int> step;	   //��que���ж�Ӧ ��Ӧ�ַ�������Ӧ��ƥ��
map<string, int> mp;    //��֦�� ���ַ����Ƿ��Ѿ���ƥ���)
int n;
int bfs() {
	bool bo = false;                                //�õ����մ����˳�ѭ��������
	while (que.empty() == 0&&step.front()<10)      //���в�Ϊ���Ҳ���С��10
	{
		if (mp[que.front()] == 1)                  //��ǰ����������  ����
		{
			step.pop();
			que.pop();
			continue;
		}
		mp[que.front()] = 1;                       //��Ǳ��������ַ���
		for (int i = 0; i < n; i++)                //����ת����ʽ
		{
			string str = que.front();              
			while (true)                           //ѭ������ǰ�����޵�ǰ��ת����
			{
				int place = str.find(A[i]);        //�õ��Ӵ���λ��
				if (place == -1)				  //û���Ӵ� �˳�ѭ��
				   	break;
				//���ת��������ַ��� ���������
				string str_1 = que.front();        
				str_1.replace(place, A[i].size(), B[i]);
				que.push(str_1);
				//������һ�γ��ֵ��Ӵ�����ĸ���еĵ�ǰ�����Ӵ��ĵ�һ����ĸ����������ţ�
				str[place] = '*';
				//�´�������ջ
				step.push(step.front() + 1);
				//�Ƿ��˳�ѭ��
				if (str_1 == str_en)
				{
					bo = true;
					break;
				}
			}
			//�Ƿ��˳�ѭ��
			if (bo)
				break;
		}
		//���Ӳ���
		que.pop();
		step.pop();
		//���ز�����βԪ��  ����С����
		if (bo)
			return step.back();
	}
	return 0;
}
int main() {
	cin >> str_st >> str_en; 
	//��һ�������������
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