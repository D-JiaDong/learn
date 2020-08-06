//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct stru{
//	int x; int y;
//};
//bool cmp(stru a,stru b)
//{
//	return a.x > b.x;//从大到小
//	//return a.x<b.x;//从小到大
//}
//stru arr[6];
//int main()
//{
//	arr[0] = { 1,2 }; arr[1] = { 4,3 };
//	arr[2] = { 2,7 }; arr[3] = { 3,4 };
//	arr[4] = { 5,6 }; arr[5] = { 0,8 };
//	cout << "排序前：";
//	for (int i = 0; i < 6; i++)
//		cout << '(' << arr[i].x << ',' << arr[i].y << ')' << ' ';
//	cout << endl;
//	sort(arr, arr + 6,cmp);
//	cout << "排序后：";
//	for (int i = 0; i < 6; i++)
//		cout << '(' << arr[i].x << ',' << arr[i].y << ')' << ' ';
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double num = 3.14159;
	cout << "原数：" << num << endl;                                         //3.1415926535

	cout << "保留两位小数：" << endl;
	//{
	     cout << setiosflags(ios::fixed) << setprecision(2) << num << endl;//3.14
		 cout << fixed << setprecision(2) << num << endl;                  //3.14
   
		 cout << setiosflags(ios::fixed) << setprecision(6) << num << endl;
		 cout << fixed << setprecision(7) << num << endl;              													   
																		   
	//}
	system("pause");
	return 0;
}