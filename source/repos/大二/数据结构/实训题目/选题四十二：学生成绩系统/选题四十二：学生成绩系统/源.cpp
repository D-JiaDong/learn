#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
struct Student {
	string student_No;   //ѧ��
	string name;         //����
	string sex;          //�Ա�
	string Dormitory_No; //�����
	string phone_num;    //�ֻ���
	//�����Ϣ����
	void _search(){
		cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t" << "�������" << "\t" << "�绰����" << endl;
		cout << student_No << "\t" << name << "\t" << sex << "\t" << Dormitory_No << "\t" << phone_num << endl;
	}
};
Student stu[100];
struct Grade{
	string student_No;          //ѧ��
	string sourse_No;           //�γ̱��
	string sourse_name;         //�γ�����
	double credit;              //ѧ��
	double Usually_result;      //ƽʱ�ɼ�
	double experimental_result; //ʵ��ɼ�
	double book_result;         //����ɼ�
	double intergrated_result;  //�ۺϳɼ�
	double Takehome_credit;     //ʵ��ѧ��
};
//��B.txt�ļ���������ɼ�����
//�����㲹ȫ�ۺϳɼ���ʵ��ѧ��
void logging_data() {
	ofstream wr("B.txt", ios::out);
	if (!wr)
	{
		cout << "�޷����ļ�" << endl;
		return;
	}
	wr << "ѧ�� �γ̱�� �γ����� ѧ�� ƽʱ�ɼ� ʵ��ɼ� ����ɼ� �ۺϳɼ� ʵ��ѧ��" << endl;
	Grade grad;
	cout << "������Ҫ������������ݣ�"; int n; cin >> n;
	cout << "�밴�գ�ѧ�� �γ̱�� �γ����� ѧ�� ƽʱ�ɼ� ʵ��ɼ� ����ɼ�  �ۺϳɼ� ʵ��ѧ�ֵ�˳������"<<n<<"������" << endl;
	while(n--)
	{
		cin >> grad.student_No >> grad.sourse_No >> grad.sourse_name
			>> grad.credit >> grad.Usually_result >> grad.experimental_result 
			>> grad.book_result;
		wr << grad.student_No <<' '<< grad.sourse_No << ' ' << grad.sourse_name
		   << ' ' << grad.credit << ' ' << grad.Usually_result << ' ' << grad.experimental_result
		   << ' ' << grad.book_result<<' ';
			/*
			�ۺϳɼ��ļ���:������γ̵�ʵ��ɼ�Ϊ - 1�����ʾ��ʵ�飬�ۺϳɼ� =
			ƽʱ�ɼ� * 30 % +����ɼ� * 70 % ; ���ʵ��ɼ���Ϊ - 1, ��ʾ���γ���ʵ��,
			�ۺϳɼ� = ƽʱ�ɼ� * 15 % +ʵ��ɼ� * .15%+����ɼ� * 70 % .
			 ʵ��ѧ�ֵļ���: ���õȼ�ѧ����. 
			�ۺϳɼ���90-100֮�� ,Ӧ��ѧ��=ѧ��*100% 
			�ۺϳɼ���70-90֮�� ,Ӧ��ѧ��=ѧ��*80%
			�ۺϳɼ���60-70֮�� ,Ӧ��ѧ��=ѧ��*65%
			�ۺϳɼ���60���� ,Ӧ��ѧ��=ѧ��*0%
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

//��A.txt��B.txt���� ɾ������
void Delete() {
	cout << "������Ҫɾ��ѧ����ѧ�ţ�";
	string NUM;
	cin >> NUM;
	//**********************************************************
	//ɾ��A.txt
	ifstream re_A("A.txt", ios::in);
	ofstream wr_A("FU.txt", ios::out);
	string str_A;              //��Ŷ�ȡ��ÿ������
	//��ȡ��һ�еķ����ݵı�ʶ
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
	//ɾ��b.txt
	ifstream re_B("B.txt", ios::in);
	ofstream wr_B("FU.txt", ios::out);
	string str_B;              //��Ŷ�ȡ��ÿ������
	//��ȡ��һ�еķ����ݵı�ʶ
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

//�ۺϳɼ�����
bool cmp1_1(Grade a, Grade b)
{
	return a.intergrated_result< b.intergrated_result;
}
//�ۺϳɼ�����
bool cmp1_2(Grade a, Grade b)
{
	return a.intergrated_result > b.intergrated_result;
}
//ʵ��ѧ������
bool cmp2_1(Grade a, Grade b)
{
	return a.Takehome_credit < b.Takehome_credit;
}
//ʵ��ѧ�ֽ���
bool cmp2_2(Grade a, Grade b)
{
	return a.Takehome_credit > b.Takehome_credit;
}
//���ݾ���ѡ������ ���
void Sort() {
	ifstream re("B.txt", ios::in);
	Grade gra[100];              //��Ŷ�ȡ������Ϣ
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
	cout << "��1���ۺϳɼ�����" << "\t" << "��2���ۺϳɼ�����" << endl;
	cout << "��3��ʵ��ѧ������" << "\t" << "��4��ʵ��ѧ�ֽ���" << endl;
	cout << "**********************************************" << endl;
	cout << "��ѡ�����򷽷���";
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
	cout<< "ѧ��     �γ̱��     �γ�����     ѧ��     ƽʱ�ɼ�     ʵ��ɼ�     ����ɼ�     �ۺϳɼ�     ʵ��ѧ��" << endl;
	for (int i = 0; i < n; i++)
		cout << gra[i].student_No << '\t' << gra[i].sourse_No << '\t' << gra[i].sourse_name
		<< '\t' << gra[i].credit << '\t' << gra[i].Usually_result << '\t' << gra[i].experimental_result
		<< '\t' << gra[i].book_result << '\t' << gra[i].intergrated_result<< '\t' <<gra[i].Takehome_credit << endl;
	cout << "........" << endl;
}

//��ѧ��������Ϣ���в�ѯ
void search_1() {
	ifstream re("A.txt", ios::in);
	Student stu[100];              //��Ŷ�ȡ������Ϣ
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
	cout << "(1) ���˲�ѯ" << endl;
	cout << "(2) �����ѯ" << endl;
	cout << "*******************" << endl;
	int choose;
	cout << "�������ѯ��ʽ��"; cin >> choose;
	if (choose == 1)
	{
		cout << "*******************" << endl;
		cout << "(1) ����ѧ�Ų�ѯ" << endl;
		cout << "(2) ����������ѯ" << endl;
		cout << "*******************" << endl;
		int choose1;
		cout << "�������ѯ��ʽ��"; cin >> choose1;
		if (choose1 == 1)
		{
			string num;
			cout << "������ѧ��ѧ�ţ�"; cin >> num;
			for (int i = 0; i < n; i++)
				if (stu[i].student_No == num)
				{
					stu[i]._search();
				}
		}
		if (choose1 == 2)
		{
			string Name;
			cout << "������ѧ��������"; cin >> Name;
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
		cout << "����������ţ�"; cin >> Dormitory;
		for (int i = 0; i < n; i++)
		{
			if (stu[i].Dormitory_No == Dormitory)
			{
				stu[i]._search();
			}
		}
	}
}

//�ڳɼ���ѯʱ����A.txt��ȡָ��ѧ��ѧ��������
string search_2name(string num) {
	ifstream re("A.txt", ios::in);
	Student stu[100];              //��Ŷ�ȡ������Ϣ
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
//��ѧ���ɼ����в�ѯ
void search_2() {
	ifstream re("B.txt", ios::in);
	Grade gra[100];              //��Ŷ�ȡ������Ϣ
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
	cout << "������ѧ�ţ�";
	string num;
	cin >> num;
	for (int i = 0; i < n; i++)
	{
		if (gra[i].student_No == num)
		{
			cout << "ѧ	��:" << gra[i].student_No << "\t\t" << "��	��:" << search_2name(gra[i].student_No) << endl;
			break;
		}
	}
	double coun = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (gra[i].student_No == num)
		{
			cout << "�γ̱�ţ�" << gra[i].sourse_No<<'\t' << "�γ����ƣ�" << gra[i].sourse_name << '\t' << "�ۺϳɼ���" << gra[i].intergrated_result << '\t' << "ʵ��ѧ�֣�" << gra[i].Takehome_credit << endl;
			coun++;
			sum += gra[i].Takehome_credit;
		}
	}
	cout << "����:" << coun << "��" << "\t" << "ʵ����ѧ��Ϊ��" << sum << endl;
}

//��ѯ�˵�
void search() {
	cout << "*******************"<<endl;
	cout << "(1) ѧ�����������ѯ" << endl;
	cout << "(2) �ɼ���ѯ" << endl;
	cout << "*******************" << endl;
	int choose;
	cout << "�������ѯ��ʽ��";
	cin >> choose;
	if (choose == 1)
		search_1();
	if (choose == 2)
		search_2();
}

//���˵�
int main() {
	bool bo = true;
	while (bo)
	{
		cout << "**********************************************" << endl;
		cout << "��1������¼��" << "\t\t" << "��2��ɾ��" << endl;
		cout << "��3������" << "\t\t" << "��4����ѯ" << endl;
		cout << " (5���˳�" << endl;
		cout << "**********************************************" << endl;
		cout << "������Ҫ���в�����";
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