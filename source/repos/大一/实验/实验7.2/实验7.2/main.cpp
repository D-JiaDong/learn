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
//长方体
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
		cout << "长方体:"<<endl;
	}
};
inline Cube::Cube()
{
	cout << "请输入长方体的长宽高:" << endl;
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
//球体
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
		cout << "球体:" << endl;
	}
};
inline Sphere::Sphere()
{
	cout << "请输入球体的半径:" << endl;
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
//圆柱体
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
		cout << "圆柱体:"<<endl;
	}
};
inline Cylinder::Cylinder()
{
	cout << "请输入圆柱体的底面半径和高:" << endl;
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
//全局函数

void print0(Container &lt)
{
	lt.pri();
}
void show(Container &lt)
{
	cout << "面积:" << lt.mj() << "*******体积:" << lt.tj();
	cout << endl;
}

//主函数
int main()
{
	//Container *LT;
	Cube c1;
	//LT = &c1;
	//cout<<"该长方体的面积:"<<LT->mj()<<"体积:"<<LT->tj()<<endl;
	Sphere c2;
	//LT = &c2;
	//cout<<"该球体的面积:"<<LT->mj()<<"体积:"<<LT->tj()<<endl;
	Cylinder c3;
	//LT = &c3;
	//cout<<"该圆柱体的面积:"<<LT->mj()<<"体积:"<<LT->tj()<<endl;
	
	print0(c1);
	show(c1);
	print0(c2);
	show(c2);
	print0(c3);
	show(c3);
	system("pause");
	return 0;
}