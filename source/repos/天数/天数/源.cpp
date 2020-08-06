//struct tm {
//	int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
//	int tm_min;   // 分，范围从 0 到 59
//	int tm_hour;  // 小时，范围从 0 到 23
//	int tm_mday;  // 一月中的第几天，范围从 1 到 31
//	int tm_mon;   // 月，范围从 0 到 11
//	int tm_year;  // 自 1900 年起的年数
//	int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
//	int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
//	int tm_isdst; // 夏令时
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

	//获取当前时间
	time_t now = time(0);
	tm *localt = localtime(&now);
	int loc_year = localt->tm_year + 1900;   // 自 1900 年起的年数，加1900
	int loc_mon = localt->tm_mon+1;            //从 0 开始，加1
	int loc_day = localt->tm_mday;           //从 1 开始，表示本月第几天

	//得到出生日期
	int bri_year;
	int bri_mon;
	int bri_day;
	cout << "请输入出生年" << endl;
	cin>>bri_year;
	cout << "请输入出生月" << endl;
	cin >> bri_mon;
	cout << "请输入出生日" << endl;
	cin >> bri_day;

	
	
	//出生年日期在该年的天数
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

	//当前日期在改该年的天数
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
	//本年 与 分本年 出生
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
