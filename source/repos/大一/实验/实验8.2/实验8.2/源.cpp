//2������һ���ַ�����string��������Ų��������ַ��������������
//�� = = ������<���͡�>�������������ַ����ĵ��ڡ�С�ںʹ��ڵıȽ����㡣
#include <iostream>
using namespace std;
#include<string>
class String
{
public:
	String( const char *str);
	friend bool operator > (String &string1, String &string2);
	friend bool operator < (String &string1, String &string2);
	friend bool operator == (String &string1, String &string2);
	void display();
private:
	 const char *p;
};
String::String(const char *str)
{
	p = str;
}
void String::display()                             //���p��ָ����ַ���
{
	cout << p;
}

bool operator > (String &string1, String &string2)
{
	if (strcmp(string1.p, string2.p) > 0)
		return true;
	else
		return false;
}

bool operator < (String &string1, String &string2)
{
	if (strcmp(string1.p, string2.p) < 0)
		return true;
	else
		return false;
}

bool operator == (String &string1, String &string2)
{
	if (strcmp(string1.p, string2.p) == 0)
		return true;
	else
		return false;
}

//void compare(String &string1, String &string2)
//{
//	if (operator>(string1, string2) == 1)
//	{
//		string1.display(); cout << ">"; string2.display();
//	}
//	else
//		if (operator<(string1, string2) == 1)
//		{
//			string1.display(); cout << "<"; string2.display();
//		}
//		else
//			if (operator==(string1, string2) == 1)
//			{
//				string1.display(); cout << "="; string2.display();
//			}
//	cout << endl;
//}
int main()
{
	String string1("Hello"), string2("Book"), string3("Computer"), string4("Hello");
	/*compare(string1, string2);
	compare(string2, string3);
	compare(string1, string4);*/
	cout << boolalpha << operator > (string1, string2) << endl;
	cout << boolalpha << operator == (string2, string3) << endl;
	cout << boolalpha << operator < (string3, string4) << endl;
	system("pause");
	return 0;
}

