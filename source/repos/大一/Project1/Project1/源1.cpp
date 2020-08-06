#include"标头.h"
#include"源.cpp"
int main()
{
	Teacher_Cadre a("张三", 34, "男", "长春市", "111110", "教授", "院长", 20000);
	a.show(a);
	cout << a.post << "   " << a.wages << endl;
	system("pause");
	return 0;
}
