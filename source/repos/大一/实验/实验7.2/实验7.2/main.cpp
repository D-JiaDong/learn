//Cube Sphere Cylinder
#include<iostream>
# define pi 3.1415926
using namespace std;
class Container
{
public:
	Container() {};
	virtual double mj() = 0;
	virtual double tj() = 0;
	virtual void pri() = 0;
};
//������
class Cube :public Container
{
protected:
	double x, y, z;
public:
	Cube();
	double mj();
	double tj();
	void pri()
	{
		cout << "������:"<<endl;
	}
};
inline Cube::Cube()
{
	cout << "�����볤����ĳ����:" << endl;
	cin >> x >> y >> z;
}
inline double Cube::mj()
{
	return 2 * (x*y + x * z + y * z);
}
inline double Cube::tj()
{
	return x * y*z;
}
//����
class Sphere :public Container
{
protected:
	double R;
public:
	Sphere();
	double mj();
	double tj();
	void pri()
	{
		cout << "����:" << endl;
	}
};
inline Sphere::Sphere()
{
	cout << "����������İ뾶:" << endl;
	cin >> R;
}
inline double Sphere::mj()
{
	return 4 * pi*R*R;
}
inline double Sphere::tj()
{
	return 4 / 3 * pi*R*R*R;
}
//Բ����
class Cylinder :public Container
{
protected:
	double R, H;
public:
	Cylinder();
	double mj();
	double tj();
	void pri()
	{
		cout << "Բ����:"<<endl;
	}
};
inline Cylinder::Cylinder()
{
	cout << "������Բ����ĵ���뾶�͸�:" << endl;
	cin >> R >> H;
}
inline double Cylinder::mj()
{
	return 2 * (pi*R*R) + 2 * pi*R*H;
}
inline double Cylinder::tj()
{
	return pi * R*R*H;
}
//ȫ�ֺ���

void print0(Container &lt)
{
	lt.pri();
}
void show(Container &lt)
{
	cout << "���:" << lt.mj() << "*******���:" << lt.tj();
	cout << endl;
}

//������
int main()
{
	//Container *LT;
	Cube c1;
	//LT = &c1;
	//cout<<"�ó���������:"<<LT->mj()<<"���:"<<LT->tj()<<endl;
	Sphere c2;
	//LT = &c2;
	//cout<<"����������:"<<LT->mj()<<"���:"<<LT->tj()<<endl;
	Cylinder c3;
	//LT = &c3;
	//cout<<"��Բ��������:"<<LT->mj()<<"���:"<<LT->tj()<<endl;
	
	print0(c1);
	show(c1);
	print0(c2);
	show(c2);
	print0(c3);
	show(c3);
	system("pause");
	return 0;
}