#include<iostream>
using namespace std;
int sum;
struct child {
	int high;          //���
	int index;         //�±�
	int unhap_n=1;     //�����˶�
};
child ch[100];
int n;
int main()
{
	cin >> n;
	int max_ = n;          //��¼��ǰӦ�ð��ŵ�λ��
	for (int i = 0; i < n; i++)
	{
		cin >> ch[i].high;
		ch[i].index = i;
	}
	while (1)
	{
		if (max_ <= 1)
			break;
		//�ҳ�δ����λ����������
		child max_ch=ch[0];
		for (int i = 0; i < max_; i++)
		{
			if (ch[i].high >= max_ch.high)
				max_ch = ch[i];
		}
		//ǰ��
		for (int i = max_ch.index+1; i < max_; i++)
		{
			//�Ӳ����˶�
			sum += ch[i].unhap_n;
			//cout << ch[i].unhap_n << endl;
			//�ı�С���Ѷ�Ӧ�±� �Ͳ����˶�
			ch[i].index--;
			ch[i].unhap_n++;
			//ǰ��
			ch[i-1]=ch[i];
		}
		//����
		int j = max_ch.index + 1;
		for (j; j <max_;j++)
		{
			//�Ӳ�ȷ����
			sum += max_ch.unhap_n;
			//cout <<"**"<<max_ch.unhap_n<< endl;
			//�ı�С���Ѷ�Ӧ�±� �Ͳ����˶�
			max_ch.index++;
			max_ch.unhap_n++;
			//��ǰ�����ߵ�С�����Ƶ���ǰ��Ҫ���ŵ���ĩβλ��
			ch[max_ - 1] = max_ch;
		}
		max_--;//��Ҫ���ŵ���ĩβλ��ǰ��
	}
	cout << sum << endl;
	system("pause");
	return 0;
}