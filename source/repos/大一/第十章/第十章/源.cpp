#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream fs;
	fs.open("3", ios::in | ios::out);
	if (fs.fail())
		cout << "open file errer!";
	else
	{
		fs.seekp(4, ios::beg);
		fs.put('Y');
		char contents[10];
		fs.seekg(0, ios::beg);
		fs.getline(contents, 10);
		cout << contents;
	}
	system("pause");
	return 0;
}
//  ostream& seekp(streampos pos);
//  ostream& seek(streamoff off,ios::seek_dir dir);
//  ostream& seekg(streampos,pos);
//  ostream& seekq(streamoffoff,ios::seek_dir dir);
//  在函数参数中，类型streampos和streamoff等效于long类型，他们分别限制了文件的位置
//以及读写操作的相对偏移范围。参数dir表示文件指针的起始位置，off表示相对于真个起始
//位置的位移量.
//ios::beg 从文件头开始，把文件指针移动由off指定的距离。
//ios::cur 从当前位置开始，把文件指针移动由off指定的距离，
//ios::end 从文件末尾开始，把文件指针移动由off指定的距离。
//  当dir为ios::beg时，off的值为正数；当dir为ios::end时，off的值为负数，而当dir为
//ios::cur时，off的值可以为正数，也可以为负数。off的值为正数时从前向后移动文件指针
//为负数时从后向前移动文件指针。
//  函数seekg（）用于输入文件，将相应文件的读指针从dir说明的位置移动off字节；函数
//seekp()用于输出文件，将相应文件的写指针从dir说明的位置移动off字节。