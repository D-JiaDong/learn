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
//  �ں��������У�����streampos��streamoff��Ч��long���ͣ����Ƿֱ��������ļ���λ��
//�Լ���д���������ƫ�Ʒ�Χ������dir��ʾ�ļ�ָ�����ʼλ�ã�off��ʾ����������ʼ
//λ�õ�λ����.
//ios::beg ���ļ�ͷ��ʼ�����ļ�ָ���ƶ���offָ���ľ��롣
//ios::cur �ӵ�ǰλ�ÿ�ʼ�����ļ�ָ���ƶ���offָ���ľ��룬
//ios::end ���ļ�ĩβ��ʼ�����ļ�ָ���ƶ���offָ���ľ��롣
//  ��dirΪios::begʱ��off��ֵΪ��������dirΪios::endʱ��off��ֵΪ����������dirΪ
//ios::curʱ��off��ֵ����Ϊ������Ҳ����Ϊ������off��ֵΪ����ʱ��ǰ����ƶ��ļ�ָ��
//Ϊ����ʱ�Ӻ���ǰ�ƶ��ļ�ָ�롣
//  ����seekg�������������ļ�������Ӧ�ļ��Ķ�ָ���dir˵����λ���ƶ�off�ֽڣ�����
//seekp()��������ļ�������Ӧ�ļ���дָ���dir˵����λ���ƶ�off�ֽڡ�