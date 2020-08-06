#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
struct Student {
	string student_No;   //学号
	string name;         //姓名
	string sex;          //性别
	string Dormitory_No; //宿舍号
	string phone_num;    //手机号
	//输出信息函数
	void _search(){
		cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "宿舍号码" << "\t" << "电话号码" << endl;
		cout << student_No << "\t" << name << "\t" << sex << "\t" << Dormitory_No << "\t" << phone_num << endl;
	}
};
Student stu[100];
struct Grade{
	string student_No;          //学号
	string sourse_No;           //课程标号
	string sourse_name;         //课程名称
	double credit;              //学分
	double Usually_result;      //平时成绩
	double experimental_result; //实验成绩
	double book_result;         //卷面成绩
	double intergrated_result;  //综合成绩
	double Takehome_credit;     //实得学分
};
//对B.txt文件操作输入成绩数据
//并运算补全综合成绩和实得学分
void logging_data() {
	ofstream wr("B.txt", ios::out);
	if (!wr)
	{
		cout << "无法打开文件" << endl;
		return;
	}
	wr << "学号 课程编号 课程名称 学分 平时成绩 实验成绩 卷面成绩 综合成绩 实得学分" << endl;
	Grade grad;
	cout << "请输入要输入多少组数据："; int n; cin >> n;
	cout << "请按照：学号 课程编号 课程名称 学分 平时成绩 实验成绩 卷面成绩  综合成绩 实得学分的顺序输入"<<n<<"组数据" << endl;
	while(n--)
	{
		cin >> grad.student_No >> grad.sourse_No >> grad.sourse_name
			>> grad.credit >> grad.Usually_result >> grad.experimental_result 
			>> grad.book_result;
		wr << grad.student_No <<' '<< grad.sourse_No << ' ' << grad.sourse_name
		   << ' ' << grad.credit << ' ' << grad.Usually_result << ' ' << grad.experimental_result
		   << ' ' << grad.book_result<<' ';
			/*
			综合成绩的计算:如果本课程的实验成绩为 - 1，则表示无实验，综合成绩 =
			平时成绩 * 30 % +卷面成绩 * 70 % ; 如果实验成绩不为 - 1, 表示本课程有实验,
			综合成绩 = 平时成绩 * 15 % +实验成绩 * .15%+卷面成绩 * 70 % .
			 实得学分的计算: 采用等级学分制. 
			综合成绩在90-100之间 ,应得学分=学分*100% 
			综合成绩在70-90之间 ,应得学分=学分*80%
			综合成绩在60-70之间 ,应得学分=学分*65%
			综合成绩在60以下 ,应得学分=学分*0%
			*/
		if (grad.experimental_result == -1)
			grad.intergrated_result = grad.Usually_result*0.3 + grad.book_result*0.7;
		else
			grad.intergrated_result = grad.Usually_result*0.15 + grad.experimental_result*0.15+grad.book_result*0.7;
		if (grad.intergrated_result >=90 && grad.intergrated_result <= 100)
			grad.Takehome_credit = grad.credit;
		if (grad.intergrated_result >=70 && grad.intergrated_result < 90)
			grad.Takehome_credit = grad.credit*0.8;
		if (grad.intergrated_result >=60 && grad.intergrated_result < 70)
			grad.Takehome_credit = grad.credit*0.65;
		if (grad.intergrated_result < 60)
			grad.Takehome_credit =0;
		wr << grad.intergrated_result << ' ' << grad.Takehome_credit << endl;
	}
	wr.close();
}

//对A.txt和B.txt操作 删除数据
void Delete() {
	cout << "请输入要删除学生的学号：";
	string NUM;
	cin >> NUM;
	//**********************************************************
	//删除A.txt
	ifstream re_A("A.txt", ios::in);
	ofstream wr_A("FU.txt", ios::out);
	string str_A;              //存放读取的每行数据
	//读取第一行的非数据的标识
	getline(re_A, str_A);
	wr_A << str_A << endl;   

	while (!re_A.eof())
	{
		getline(re_A, str_A);
		int i = 0;
		if (!(str_A[0]== NUM[0]&&str_A[1]==NUM[1]))
		{
			wr_A << str_A << endl;
		}
	}
	re_A.close(); wr_A.close();
	ifstream re_A1("FU.txt", ios::in);
	ofstream wr_A1("A.txt", ios::out);
	while (!re_A1.eof())
	{
		getline(re_A1, str_A);
		wr_A1 << str_A << endl;
	}
	re_A1.close(); wr_A1.close();


	//**************************************************************
	//删除b.txt
	ifstream re_B("B.txt", ios::in);
	ofstream wr_B("FU.txt", ios::out);
	string str_B;              //存放读取的每行数据
	//读取第一行的非数据的标识
	getline(re_B, str_B);
	wr_B << str_B << endl;

	while (!re_B.eof())
	{
		getline(re_B, str_B);
		int i = 0;
		if (!(str_B[0] == NUM[0] && str_B[1] == NUM[1]))
		{
			wr_B << str_B << endl;
		}
	}
	re_B.close(); wr_B.close();
	ifstream re_B1("FU.txt", ios::in);
	ofstream wr_B1("B.txt", ios::out);
	while (!re_B1.eof())
	{
		getline(re_B1, str_B);
		wr_B1 << str_B << endl;
	}
	re_B1.close(); wr_B1.close();
}

//综合成绩升序
bool cmp1_1(Grade a, Grade b)
{
	return a.intergrated_result< b.intergrated_result;
}
//综合成绩降序
bool cmp1_2(Grade a, Grade b)
{
	return a.intergrated_result > b.intergrated_result;
}
//实得学分升序
bool cmp2_1(Grade a, Grade b)
{
	return a.Takehome_credit < b.Takehome_credit;
}
//实得学分降序
bool cmp2_2(Grade a, Grade b)
{
	return a.Takehome_credit > b.Takehome_credit;
}
//根据具体选择排序 输出
void Sort() {
	ifstream re("B.txt", ios::in);
	Grade gra[100];              //存放读取到的信息
	string str;               
	getline(re, str);
	int n = 0;
	while (re.peek()!= EOF)
	{
		getline(re, str);
		string data[7];
		int k = 0;
		int i = 0; int j = 0;
		while (k < 8)
		{
			for (j = i; j < str.length(); j++)
				if (str[j] == ' ')
						break;
			if (k == 0)
			{
				gra[n].student_No = str.substr(i, j-i);
			}
			if (k == 1)
			{
				gra[n].sourse_No = str.substr(i, j-i);
			}
			if (k == 2)
			{
				gra[n].sourse_name= str.substr(i, j - i);			  
			}
			if (k == 3)
			{
				string s = str.substr(i, j - i);
				gra[n].credit= stod(s, 0);			
			}
			if (k == 4)
			{
				string s = str.substr(i, j - i);
				gra[n].Usually_result= stod(s, 0);			
			}
			if (k ==5)
			{
				string s = str.substr(i, j - i);
				gra[n].experimental_result = stod(s, 0);				
			}
			if (k ==6)
			{
				string s = str.substr(i, j - i);
				gra[n].book_result = stod(s, 0);				
			}
			if (k == 7)
			{
				string s = str.substr(i, j - i);
				gra[n].intergrated_result = stod(s, 0);			
			}
			if (k == 8)
			{
				string s = str.substr(i, j - i);
				gra[n].Takehome_credit = stod(s, 0);
			}
			i = j + 1;
			k++;
		}
		string s = str.substr(i);
		gra[n].Takehome_credit = stod(s, 0);
		n++;
	}
	re.close();
	cout << "**********************************************" << endl;
	cout << "（1）综合成绩升序" << "\t" << "（2）综合成绩降序" << endl;
	cout << "（3）实得学分升序" << "\t" << "（4）实得学分降序" << endl;
	cout << "**********************************************" << endl;
	cout << "请选择排序方法：";
	int choose;
	cin >> choose;
	if (choose == 1)
		sort(gra, gra + 4, cmp1_1);
	if (choose == 2)
		sort(gra, gra + n, cmp1_2);
	if (choose == 3)
		sort(gra, gra + n, cmp2_1);
	if (choose ==4)
		sort(gra, gra + n, cmp2_2);
	cout << "........" << endl;
	cout<< "学号     课程编号     课程名称     学分     平时成绩     实验成绩     卷面成绩     综合成绩     实得学分" << endl;
	for (int i = 0; i < n; i++)
		cout << gra[i].student_No << '\t' << gra[i].sourse_No << '\t' << gra[i].sourse_name
		<< '\t' << gra[i].credit << '\t' << gra[i].Usually_result << '\t' << gra[i].experimental_result
		<< '\t' << gra[i].book_result << '\t' << gra[i].intergrated_result<< '\t' <<gra[i].Takehome_credit << endl;
	cout << "........" << endl;
}

//对学生基本信息进行查询
void search_1() {
	ifstream re("A.txt", ios::in);
	Student stu[100];              //存放读取到的信息
	string str;
	getline(re, str);
	int n = 0;
	while (1)
	{
		getline(re, str);
		if (str == "")
			break;
		int k = 0;
		int i = 0; int j = 0;
		while (k < 4)
		{
			for (j = i; j < str.length(); j++)
				if (str[j] == ' ')
					break;
			if (k == 0)
			{
				stu[n].student_No = str.substr(i, j - i);
			}
			if (k == 1)
			{
				stu[n].name = str.substr(i, j - i);
			}
			if (k == 2)
			{
				stu[n].sex = str.substr(i, j - i);
			}
			if (k == 3)
			{
				stu[n].Dormitory_No = str.substr(i, j - i);
			}
			i = j + 1;
			k++;
		}
		stu[n].phone_num = str.substr(i);
		n++;
	}
	re.close();
	cout << "*******************" << endl;
	cout << "(1) 个人查询" << endl;
	cout << "(2) 宿舍查询" << endl;
	cout << "*******************" << endl;
	int choose;
	cout << "请输入查询方式："; cin >> choose;
	if (choose == 1)
	{
		cout << "*******************" << endl;
		cout << "(1) 按照学号查询" << endl;
		cout << "(2) 按照姓名查询" << endl;
		cout << "*******************" << endl;
		int choose1;
		cout << "请输入查询方式："; cin >> choose1;
		if (choose1 == 1)
		{
			string num;
			cout << "请输入学生学号："; cin >> num;
			for (int i = 0; i < n; i++)
				if (stu[i].student_No == num)
				{
					stu[i]._search();
				}
		}
		if (choose1 == 2)
		{
			string Name;
			cout << "请输入学生姓名："; cin >> Name;
			for (int i = 0; i < n; i++)
			{
				if (stu[i].name == Name)
					stu[i]._search();
			}
		}
	}
	if (choose == 2)
	{
		string Dormitory;
		cout << "请输入宿舍号："; cin >> Dormitory;
		for (int i = 0; i < n; i++)
		{
			if (stu[i].Dormitory_No == Dormitory)
			{
				stu[i]._search();
			}
		}
	}
}

//在成绩查询时访问A.txt获取指定学号学生的姓名
string search_2name(string num) {
	ifstream re("A.txt", ios::in);
	Student stu[100];              //存放读取到的信息
	string str;
	getline(re, str);
	int n = 0;
	while (1)
	{
		getline(re, str);
		if (str == "")
			break;
		int k = 0;
		int i = 0; int j = 0;
		while (k < 4)
		{
			for (j = i; j < str.length(); j++)
				if (str[j] == ' ')
					break;
			if (k == 0)
			{
				stu[n].student_No = str.substr(i, j - i);
			}
			if (k == 1)
			{
				stu[n].name = str.substr(i, j - i);
			}
			if (k == 2)
			{
				stu[n].sex= str.substr(i, j - i);
			}
			if (k == 3)
			{
				stu[n].Dormitory_No = str.substr(i, j - i);
			}
			i = j + 1;
			k++;
		}
		stu[n].phone_num = str.substr(i);
		n++;
	}
	re.close();
	for (int i = 0; i < n; i++)
		if (stu[i].student_No == num)
			return stu[i].name;
}
//对学生成绩进行查询
void search_2() {
	ifstream re("B.txt", ios::in);
	Grade gra[100];              //存放读取到的信息
	string str;
	getline(re, str);
	int n = 0;
	while (re.peek() != EOF)
	{
		getline(re, str);
		string data[7];
		int k = 0;
		int i = 0; int j = 0;
		while (k < 8)
		{
			for (j = i; j < str.length(); j++)
				if (str[j] == ' ')
					break;
			if (k == 0)
			{
				gra[n].student_No = str.substr(i, j - i);
			}
			if (k == 1)
			{
				gra[n].sourse_No = str.substr(i, j - i);
			}
			if (k == 2)
			{
				gra[n].sourse_name = str.substr(i, j - i);
			}
			if (k == 3)
			{
				string s = str.substr(i, j - i);
				gra[n].credit = stod(s, 0);
			}
			if (k == 4)
			{
				string s = str.substr(i, j - i);
				gra[n].Usually_result = stod(s, 0);
			}
			if (k == 5)
			{
				string s = str.substr(i, j - i);
				gra[n].experimental_result = stod(s, 0);
			}
			if (k == 6)
			{
				string s = str.substr(i, j - i);
				gra[n].book_result = stod(s, 0);
			}
			if (k == 7)
			{
				string s = str.substr(i, j - i);
				gra[n].intergrated_result = stod(s, 0);
			}
			if (k == 8)
			{
				string s = str.substr(i, j - i);
				gra[n].Takehome_credit = stod(s, 0);
			}
			i = j + 1;
			k++;
		}
		string s = str.substr(i);
		gra[n].Takehome_credit = stod(s, 0);
		n++;
	}
	re.close();
	cout << "请输入学号：";
	string num;
	cin >> num;
	for (int i = 0; i < n; i++)
	{
		if (gra[i].student_No == num)
		{
			cout << "学	号:" << gra[i].student_No << "\t\t" << "姓	名:" << search_2name(gra[i].student_No) << endl;
			break;
		}
	}
	double coun = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (gra[i].student_No == num)
		{
			cout << "课程编号：" << gra[i].sourse_No<<'\t' << "课程名称：" << gra[i].sourse_name << '\t' << "综合成绩：" << gra[i].intergrated_result << '\t' << "实得学分：" << gra[i].Takehome_credit << endl;
			coun++;
			sum += gra[i].Takehome_credit;
		}
	}
	cout << "共修:" << coun << "科" << "\t" << "实得总学分为：" << sum << endl;
}

//查询菜单
void search() {
	cout << "*******************"<<endl;
	cout << "(1) 学生基本情况查询" << endl;
	cout << "(2) 成绩查询" << endl;
	cout << "*******************" << endl;
	int choose;
	cout << "请输入查询方式：";
	cin >> choose;
	if (choose == 1)
		search_1();
	if (choose == 2)
		search_2();
}

//主菜单
int main() {
	bool bo = true;
	while (bo)
	{
		cout << "**********************************************" << endl;
		cout << "（1）数据录入" << "\t\t" << "（2）删除" << endl;
		cout << "（3）排序" << "\t\t" << "（4）查询" << endl;
		cout << " (5）退出" << endl;
		cout << "**********************************************" << endl;
		cout << "请输入要进行操作：";
		int select;
		cin >> select;
		if (select ==1)
		{
			logging_data();
			continue;
		}
		if (select ==2)
		{
			Delete();
			continue;
		}
		if (select ==3)
		{
			Sort();
			continue;
		}
		if (select ==4)
		{
			search();
			continue;
		}
		if (select == 5)
		{
			bo = false;
		}
	}
	system("pause");
	return 0;
}