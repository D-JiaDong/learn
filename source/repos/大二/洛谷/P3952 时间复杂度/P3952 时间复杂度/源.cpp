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
#define MaxSize 30	//�����������ַ�����󳡿�����Ԫ����		
typedef struct fnode
{
	char father[MaxSize];	//��
	char wife[MaxSize];	//ĸ
	char son[MaxSize];	//��
} FamType;
typedef struct tnode
{
	char name[MaxSize];
	struct tnode *lchild, *rchild;
} BTree;					//����������

//����������
BTree *CreatBTree(char *root, FamType fam[], int n)	//��fam(��n����¼)�ݹ鴴��һ�ö�����
{
	int i = 0, j;
	BTree *bt, *p;
	bt = (BTree *)malloc(sizeof(BTree));	//�������׽ڵ�
	strcpy(bt->name, root);				//��root�е�COPY���Ƶ�bt->name��
	bt->lchild = bt->rchild = NULL;
	while (i < n && strcmp(fam[i].father, root) != 0) //�Ƚ������ַ����Ƿ���ͬ
		i++;
	if (i < n)									//�ҵ��˸������ļ�¼
	{
		p = (BTree *)malloc(sizeof(BTree));		//����ĸ�׽ڵ�
		p->lchild = p->rchild = NULL;
		strcpy(p->name, fam[i].wife);
		bt->lchild = p;
		for (j = 0; j < n; j++)						//�����ж���
			if (strcmp(fam[j].father, root) == 0)	//�ҵ�һ������
			{
				p->rchild = CreatBTree(fam[j].son, fam, n);
				p = p->rchild;
			}
	}
	return(bt);
}

//�����ű�ʾ�����������
void DispTree1(BTree *b)	//�������
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
			cout << ")";			//�ۼ�
		}
	}
}

//���������ױ�ʾ��
void DispTree2(BTree *bt)
{
	BTree *St[MaxSize], *p;
	int Level[MaxSize][2], top, n, i, x = 0, width = 4;
	int flag = 0;
	if (bt != NULL)
	{
		cout << "  >>���������ױ�ʾ��:" << endl;
		top = 1;
		St[top] = bt;				//���ڵ��ջ
		Level[top][0] = width;

		while (top > 0)
		{
			p = St[top];			//��ջ��������ʾ�ýڵ�ֵ
			n = Level[top][0];
			for (i = 1; i <= n; i++)  //����nΪ��ʾ����,�ַ����Ҷ�����ʾ
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
			{								//�����������ڵ��ջ
				top++;
				St[top] = p->lchild;
				Level[top][0] = 0;		//��ʾ������width
				Level[top][1] = 1;			//Ϊ���ӽڵ�				
			}
			if (p->lchild != NULL && p->rchild != NULL)
			{
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//��ʾ������width
				Level[top][1] = 2;			//Ϊ�Һ��ӽڵ�
			}
			if (p->rchild != NULL && p->lchild == NULL)
			{
				//�����������ڵ��ջ
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//��ʾ������width
				Level[top][1] = 2;			//Ϊ�Һ��ӽڵ�
			}
		}
	}
}

//�԰����ʾ�����
void DispTree3(BTree *bt)
{
	BTree *St[MaxSize], *p;
	int Level[MaxSize][2], top, n, i, width = 4;
	if (bt != NULL)
	{
		cout << "  >>���װ����ʾ��:" << endl;
		top = 1;
		St[top] = bt;				//���ڵ��ջ
		Level[top][0] = width;
		while (top > 0)
		{
			p = St[top];			//��ջ��������ʾ�ýڵ�ֵ
			n = Level[top][0];
			for (i = 1; i <= n; i++)  //����nΪ��ʾ����,�ַ����Ҷ�����ʾ
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
			{								//�����������ڵ��ջ
				top++;
				St[top] = p->rchild;
				Level[top][0] = n + width;		//��ʾ������width
				Level[top][1] = 2;			//Ϊ�Һ��ӽڵ�
			}
			if (p->lchild != NULL)
			{								//�����������ڵ��ջ
				top++;
				St[top] = p->lchild;
				Level[top][0] = n + width;		//��ʾ������width
				Level[top][1] = 1;			//Ϊ���ӽڵ�
			}
		}
	}
}

//��������ݹ��㷨��nameΪxm�Ľڵ�
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

//���ĳ�˵����ж���
void FindSon(BTree *bt)
{
	char xm[MaxSize];
	BTree *p;
	cout << "  >>��������:";
	cin >> xm;
	p = FindNode(bt, xm);
	if (p == NULL)
		cout << "  >>������" << xm << "�ĸ���" << endl;
	else
	{
		p = p->lchild;
		if (p == NULL)
			cout << "  >>" << xm << "û������" << endl;
		else
		{
			p = p->rchild;
			if (p == NULL)
				cout << "  >>" << xm << "û�ж���!" << endl;
			else
			{
				cout << "  >>" << xm << "�Ķ���:" << " ";
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

//���ú���ǵݹ������������Ӹ��ڵ㵽*s�ڵ��·��
int Path(BTree *bt, BTree *s)
{
	BTree *St[MaxSize];
	BTree *p;
	int i, flag, top = -1;				//ջָ���ó�ֵ
	do
	{
		while (bt)                 	//��bt��������ڵ��ջ
		{
			top++;
			St[top] = bt;
			bt = bt->lchild;
		}
		p = NULL;                   	//pָ��ǰ�ڵ��ǰһ���ѷ��ʵĽڵ�
		flag = 1;                   	//����bt�ķ��ʱ��Ϊ�ѷ��ʹ�
		while (top != -1 && flag)
		{
			bt = St[top];          	//ȡ����ǰ��ջ��Ԫ��
			if (bt->rchild == p)      //�����������ڻ��ѱ�����,����֮
			{
				if (bt == s)          //��ǰ���ʵĽڵ�ΪҪ�ҵĽڵ�,���·��
				{
					cout << "  >>��������:";
					for (i = 0; i < top; i++)
						cout << St[i]->name << " ";
					cout << endl;
					return 1;

				}
				else
				{
					top--;
					p = bt;           //pָ���򱻷��ʵĽ�
				}
			}
			else
			{
				bt = bt->rchild;      //btָ��������
				flag = 0;            	//����δ�����ʵı��
			}
		}
	} while (top != -1);				//ջ����ʱѭ��
	return 0;						//�������ʱ����0
}

//���ĳ�˵���������
void Ancestor(BTree *bt)
{
	BTree *p;
	char xm[MaxSize];
	cout << "  >>��������:";
	cin >> xm;
	p = FindNode(bt, xm);
	if (p != NULL)
		Path(bt, p);
	else
		cout << "  >>���޴���" << endl;
}

//��������ļ�ȫ����¼
void DelAll(FamType fam[], int &n)
{
	FILE *fp;
	if ((fp = fopen("fam.dat", "wb")) == NULL)
	{
		cout << "  >>���ܴ򿪼����ļ�" << endl;
		return;
	}
	n = 0;
	fclose(fp);
}

//�������ļ�����fam������
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
	fseek(fp, 0, 2);				//�����ļ�λ��ָ���Ƶ������ļ�β
	len = ftell(fp);    			//len��������ļ�����
	rewind(fp);					//�����ļ�λ��ָ���Ƶ������ļ���
	n = len / sizeof(FamType); 		//n��������ļ��еļ�¼����
	for (i = 0; i < n; i++)
		fread(&fam[i], sizeof(FamType), 1, fp);//�������ļ��е����ݶ���fam��
	fclose(fp);
}

//��fam����������ݼ����ļ�
void SaveFile(FamType fam[], int n)
{
	int i;
	FILE *fp;
	if ((fp = fopen("fam.dat", "wb")) == NULL)
	{
		cout << "  >>���ݼ����ļ����ܴ�" << endl;;
		return;
	}
	for (i = 0; i < n; i++)
		fwrite(&fam[i], sizeof(FamType), 1, fp);
	fclose(fp);
}

//���һ����¼
void InputFam(FamType fam[], int &n)
{
	cout << "  >>���븸�ס�ĸ�׺Ͷ�������:";
	cin >> fam[n].father;
	cin >> fam[n].wife;
	cin >> fam[n].son;
	n++;
}

//��������ļ�ȫ����¼
void OutputFile(FamType fam[], int n)
{
	int i;
	if (n <= 0)
	{
		cout << "  >>û���κμ�¼" << endl;
		return;
	}
	cout << "          ����     ĸ��      ����" << endl;
	cout << "       ------------------------------" << endl;
	for (i = 0; i < n; i++)
		printf("  %10s%10s%10s\n", fam[i].father, fam[i].wife, fam[i].son);
	cout << "       ------------------------------" << endl;
}
int main()
{

}