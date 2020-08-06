//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<stack>
//using namespace std;
//int n;
//class fory
//{
//public:
//	char fe;
//	char var;
//	int st = 0;
//	int en = 0;
//	char re = 0;
//	int re_c = 0;
//
//};
//char cplex[20];
//int ans[20];
//int main()
//{
//	cin >> n;
//	int N = n;
//	while (n--)
//	{
//		int row;
//		int cx = 0;
//		cin >> row;
//		cin >> cplex;
//		if (strlen(cplex) == 4)
//			cx = 0;
//		else
//		{
//			int i = 4;
//			while (cplex[i] >= 48 && cplex[i] <= 57)
//			{
//				cx = cx * 10 + (cplex[i] - 48);
//				i++;
//			}
//		}
//		int re_cx = 0, max_cx = 0, re = 0;
//		stack<fory> s;
//		int tf = 0;
//		while (row--)
//		{
//			fory fo;
//			char c;
//			while (1)
//			{
//				c = getchar();
//				if (c == 'F' || c == 'E')
//					break;
//			}
//			if (c == 'F')
//			{
//				fo.fe = c;
//				cin >> fo.var;
//				char str = getchar();
//				str = getchar();
//				if (str >= 48 && str <= 57)
//				{
//					while ((str >= 48 && str <= 57) || str == 'n')
//					{
//						fo.st = fo.st * 10 + (str - 48);
//						str = getchar();
//					}
//				}
//				else
//				{
//					fo.st = 0xfffffff;
//					while ((str >= 48 && str <= 57) || str == 'n')
//						str = getchar();
//				}
//				str = getchar();
//				if (str >= 48 && str <= 57)
//				{
//					while ((str >= 48 && str <= 57) || str == 'n')
//					{
//						fo.en = fo.en * 10 + (str - 48);
//						str = getchar();
//					}
//				}
//				else
//				{
//					fo.en = 0xfffffff;
//					while ((str >= 48 && str <= 57) || str == 'n')
//						str = getchar();
//				}
//				if ((fo.st == 0xfffffff && fo.en != 0xfffffff) || (fo.st > fo.en))
//				{
//					re++;
//					fo.re = 1;
//				}
//				if (fo.en == 0xfffffff && fo.st != 0xfffffff)
//				{
//					if (re == 0)
//					{
//						fo.re_c = 1;
//						re_cx++;
//					}
//				}
//				fory fo_zc[200];
//				int i = 0;
//				bool bo = false;
//				while (!s.empty())
//				{
//					fo_zc[i++] = s.top();
//					s.pop();
//					if (fo_zc[i - 1].var == fo.var)
//					{
//						bo = true;
//						break;
//					}
//				}
//				for (int j = i - 1; j >= 0; j--)
//					s.push(fo_zc[j]);
//				if (bo)
//				{
//					tf = 1;
//				}
//				s.push(fo);
//			}
//			else
//			{
//				if (!s.empty())
//				{
//					if (s.top().re == 1)
//						re--;
//					max_cx = re_cx > max_cx ? re_cx : max_cx;
//					if (s.top().re_c == 1)
//						re_cx--;
//					s.pop();
//				}
//				else
//					tf = 1;
//			}
//		}
//		if (!s.empty())
//			tf = 1;
//		if (max_cx != cx && tf == 0)
//			tf = 2;
//		if (tf == 0)
//			ans[n] = 0;
//		else
//			if (tf == 1)
//				ans[n] = 1;
//			else
//			{
//				ans[n] = 2;
//			}
//	}
//	for (int i = N - 1; i >= 0; i--)
//		if (ans[i] == 0)
//			cout << "Yes" << endl;
//		else
//			if (ans[i] == 1)
//				cout << "ERR" << endl;
//			else
//				cout << "No" << endl;
//	system("pause");
//	return 0;
//}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include<iostream>
using namespace std;
#define MaxSize 30	//代表了姓名字符、最大场宽、数组元素树		
typedef struct fnode
{
	char father[MaxSize];	//父
	char wife[MaxSize];	//母
	char son[MaxSize];	//子
} FamType;
typedef struct tnode
{
	char name[MaxSize];
	struct tnode *lchild, *rchild;
} BTree;					//家谱树类型

//创建二叉树
BTree *CreatBTree(char *root, FamType fam[], int n)	//从fam(含n个记录)递归创建一棵二叉树
{
	int i = 0, j;
	BTree *bt, *p;
	bt = (BTree *)malloc(sizeof(BTree));	//创建父亲节点
	strcpy(bt->name, root);				//将root中的COPY复制到bt->name中
	bt->lchild = bt->rchild = NULL;
	while (i < n && strcmp(fam[i].father, root) != 0) //比较两个字符串是否相同
		i++;
	if (i < n)									//找到了该姓名的记录
	{
		p = (BTree *)malloc(sizeof(BTree));		//创建母亲节点
		p->lchild = p->rchild = NULL;
		strcpy(p->name, fam[i].wife);
		bt->lchild = p;
		for (j = 0; j < n; j++)						//找所有儿子
			if (strcmp(fam[j].father, root) == 0)	//找到一个儿子
			{
				p->rchild = CreatBTree(fam[j].son, fam, n);
				p = p->rchild;
			}
	}
	return(bt);
}

//以括号表示法输出二叉树
void DispTree1(BTree *b)	//先序遍历
{
	if (b != NULL)
	{
		cout << b->name;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DispTree1(b->lchild);
			if (b->rchild != NULL)
				cout << ",";
			DispTree1(b->rchild);
			cout << ")";			//累计
		}
	}
}

//二叉树家谱表示法
void DispTree2(BTree *bt)
{
	BTree *St[MaxSize], *p;
	int Level[MaxSize][2], top, n, i, x = 0, width = 4;
	int flag = 0;
	if (bt != NULL)
	{
		cout << "  >>二叉树家谱表示法:" << endl;
		top = 1;
		St[top] = bt;				//根节点进栈
		Level[top][0] = width;

		while (top > 0)
		{
			p = St[top];			//退栈并凹入显示该节点值
			n = Level[top][0];
			for (i = 1; i <= n; i++)  //其中n为显示场宽,字符以右对齐显示
				cout << " ";
			cout << p->name << endl;
			if (Level[top][1] == 2 && p->lchild != NULL)
			{
				cout << p->lchild->name;
				flag = 1;
				n = 0;
			}
			top--;
			if (p->lchild != NULL)
			{								//将左子树根节点进栈
				top++;
				St[top] = p->lchild;
				Level[top][0] = 0;		//显示场宽增width
				Level[top][1] = 1;			//为左孩子节点				
			}
			if (p->lchild != NULL && p->rchild != NULL)
			{
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//显示场宽增width
				Level[top][1] = 2;			//为右孩子节点
			}
			if (p->rchild != NULL && p->lchild == NULL)
			{
				//将右子树根节点进栈
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//显示场宽增width
				Level[top][1] = 2;			//为右孩子节点
			}
		}
	}
}

//以凹入表示法输出
void DispTree3(BTree *bt)
{
	BTree *St[MaxSize], *p;
	int Level[MaxSize][2], top, n, i, width = 4;
	if (bt != NULL)
	{
		cout << "  >>家谱凹入表示法:" << endl;
		top = 1;
		St[top] = bt;				//根节点进栈
		Level[top][0] = width;
		while (top > 0)
		{
			p = St[top];			//退栈并凹入显示该节点值
			n = Level[top][0];
			for (i = 1; i <= n; i++)  //其中n为显示场宽,字符以右对齐显示
				cout << " ";
			cout << p->name;
			if (Level[top][1] == 1)
				cout << "(l)";
			else
				cout << "(r)";
			for (i = n + 1; i <= MaxSize - 6; i += 2)
				cout << "--";
			cout << endl;
			top--;
			if (p->rchild != NULL)
			{								//将右子树根节点进栈
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//显示场宽增width
				Level[top][1] = 2;			//为右孩子节点
			}
			if (p->lchild != NULL)
			{								//将左子树根节点进栈
				top++;
				St[top] = p->lchild;
				Level[top][0] = n + width;		//显示场宽增width
				Level[top][1] = 1;			//为左孩子节点
			}
		}
	}
}

//采用先序递归算法找name为xm的节点
BTree *FindNode(BTree *bt, char xm[])
{
	BTree *p = bt;
	if (p == NULL)
		return(NULL);
	else
	{
		if (strcmp(p->name, xm) == 0)
			return(p);
		else
		{
			bt = FindNode(p->lchild, xm);
			if (bt != NULL)
				return(bt);
			else
				return(FindNode(p->rchild, xm));
		}
	}
}

//输出某人的所有儿子
void FindSon(BTree *bt)
{
	char xm[MaxSize];
	BTree *p;
	cout << "  >>父亲姓名:";
	cin >> xm;
	p = FindNode(bt, xm);
	if (p == NULL)
		cout << "  >>不存在" << xm << "的父亲" << endl;
	else
	{
		p = p->lchild;
		if (p == NULL)
			cout << "  >>" << xm << "没有妻子" << endl;
		else
		{
			p = p->rchild;
			if (p == NULL)
				cout << "  >>" << xm << "没有儿子!" << endl;
			else
			{
				cout << "  >>" << xm << "的儿子:" << " ";
				while (p != NULL)
				{
					cout << p->name << " ";
					p = p->rchild;
				}
				cout << endl;
			}
		}
	}
}

//采用后序非递归遍历方法输出从根节点到*s节点的路径
int Path(BTree *bt, BTree *s)
{
	BTree *St[MaxSize];
	BTree *p;
	int i, flag, top = -1;				//栈指针置初值
	do
	{
		while (bt)                 	//将bt的所有左节点进栈
		{
			top++;
			St[top] = bt;
			bt = bt->lchild;
		}
		p = NULL;                   	//p指向当前节点的前一个已访问的节点
		flag = 1;                   	//设置bt的访问标记为已访问过
		while (top != -1 && flag)
		{
			bt = St[top];          	//取出当前的栈顶元素
			if (bt->rchild == p)      //右子树不存在或已被访问,访问之
			{
				if (bt == s)          //当前访问的节点为要找的节点,输出路径
				{
					cout << "  >>所有祖先:";
					for (i = 0; i < top; i++)
						cout << St[i]->name << " ";
					cout << endl;
					return 1;

				}
				else
				{
					top--;
					p = bt;           //p指向则被访问的结
				}
			}
			else
			{
				bt = bt->rchild;      //bt指向右子树
				flag = 0;            	//设置未被访问的标记
			}
		}
	} while (top != -1);				//栈不空时循环
	return 0;						//其他情况时返回0
}

//输出某人的所有祖先
void Ancestor(BTree *bt)
{
	BTree *p;
	char xm[MaxSize];
	cout << "  >>输入姓名:";
	cin >> xm;
	p = FindNode(bt, xm);
	if (p != NULL)
		Path(bt, p);
	else
		cout << "  >>查无此人" << endl;
}

//清除家谱文件全部记录
void DelAll(FamType fam[], int &n)
{
	FILE *fp;
	if ((fp = fopen("fam.dat", "wb")) == NULL)
	{
		cout << "  >>不能打开家谱文件" << endl;
		return;
	}
	n = 0;
	fclose(fp);
}

//读家谱文件存入fam数组中
void ReadFile(FamType fam[], int &n)
{
	FILE *fp;
	long len;
	int i;
	if ((fp = fopen("fam.dat", "rb")) == NULL)
	{
		n = 0;
		return;
	}
	fseek(fp, 0, 2);				//家谱文件位置指针移到家谱文件尾
	len = ftell(fp);    			//len求出家谱文件长度
	rewind(fp);					//家谱文件位置指针移到家谱文件首
	n = len / sizeof(FamType); 		//n求出家谱文件中的记录个数
	for (i = 0; i < n; i++)
		fread(&fam[i], sizeof(FamType), 1, fp);//将家谱文件中的数据读到fam中
	fclose(fp);
}

//将fam数组存入数据家谱文件
void SaveFile(FamType fam[], int n)
{
	int i;
	FILE *fp;
	if ((fp = fopen("fam.dat", "wb")) == NULL)
	{
		cout << "  >>数据家谱文件不能打开" << endl;;
		return;
	}
	for (i = 0; i < n; i++)
		fwrite(&fam[i], sizeof(FamType), 1, fp);
	fclose(fp);
}

//添加一个记录
void InputFam(FamType fam[], int &n)
{
	cout << "  >>输入父亲、母亲和儿子姓名:";
	cin >> fam[n].father;
	cin >> fam[n].wife;
	cin >> fam[n].son;
	n++;
}

//输出家谱文件全部记录
void OutputFile(FamType fam[], int n)
{
	int i;
	if (n <= 0)
	{
		cout << "  >>没有任何记录" << endl;
		return;
	}
	cout << "          父亲     母亲      儿子" << endl;
	cout << "       ------------------------------" << endl;
	for (i = 0; i < n; i++)
		printf("  %10s%10s%10s\n", fam[i].father, fam[i].wife, fam[i].son);
	cout << "       ------------------------------" << endl;
}
int main()
{

}