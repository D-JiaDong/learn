//struct tm {
//	int tm_sec;   // �룬������Χ�� 0 �� 59���������� 61
//	int tm_min;   // �֣���Χ�� 0 �� 59
//	int tm_hour;  // Сʱ����Χ�� 0 �� 23
//	int tm_mday;  // һ���еĵڼ��죬��Χ�� 1 �� 31
//	int tm_mon;   // �£���Χ�� 0 �� 11
//	int tm_year;  // �� 1900 ���������
//	int tm_wday;  // һ���еĵڼ��죬��Χ�� 0 �� 6��������������
//	int tm_yday;  // һ���еĵڼ��죬��Χ�� 0 �� 365���� 1 �� 1 ������
//	int tm_isdst; // ����ʱ
//}
#include<iostream>
#include<ctime>
using namespace std;
int days[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
bool YN_leap(int year)
{
	if (year % 400 != 0)
	{
		if (year % 4 == 0)
			return true;
	}
	else
		return true;
	return false;
}
int main()
{
	int SUM_DAY=0;

	//��ȡ��ǰʱ��
	time_t now = time(0);
	tm *localt = localtime(&now);
	int loc_year = localt->tm_year + 1900;   // �� 1900 �������������1900
	int loc_mon = localt->tm_mon+1;            //�� 0 ��ʼ����1
	int loc_day = localt->tm_mday;           //�� 1 ��ʼ����ʾ���µڼ���

	//�õ���������
	int bri_year;
	int bri_mon;
	int bri_day;
	cout << "�����������" << endl;
	cin>>bri_year;
	cout << "�����������" << endl;
	cin >> bri_mon;
	cout << "�����������" << endl;
	cin >> bri_day;

	
	
	//�����������ڸ��������
	int sum=0;
	for (int i = 0; i < bri_mon-1; i++)
	{
		if (days[i] != 0)
			sum += days[i];
		else if (YN_leap(bri_year))
			sum += 29;
		else
			sum += 28;
	}
	sum += bri_day;

	//��ǰ�����ڸĸ��������
	int sum_1=0;
	for (int i = 0; i < loc_mon-1; i++)
	{
		if (days[i] != 0)
			sum_1 += days[i];
		else if (YN_leap(loc_year))
			sum_1 += 29;
		else
			sum_1 += 28;
	}
	sum_1 += loc_day;
	//���� �� �ֱ��� ����
	if (bri_year == loc_year)
		SUM_DAY = sum_1 - sum;
	else
	{
		if (YN_leap(bri_year))
			SUM_DAY = 366 - sum;
		else
			SUM_DAY = 365 - sum;
		SUM_DAY += sum_1;
		for (int i = bri_year + 1; i < loc_year; i++)
		{
			if (YN_leap(i))
				SUM_DAY += 366;
			else
				SUM_DAY += 365;
		}
	}
	cout << SUM_DAY << endl;
	system("pause");
	return 0;
}
