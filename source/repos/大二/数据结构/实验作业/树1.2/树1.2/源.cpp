#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<tchar.h>
#define fileName "familyMap.dat"//定义节点最大个数
#define MaxNode 20//节点数据类型
typedef char ElemType;//二叉树节点类型(节点类型)
typedef struct btnode {
	ElemType data;				//家谱图中人员编号
	btnode * lchild;			//成员的配偶指针
	btnode * rchild;			//成员的子女及子女的兄弟指针
}BtNode;
typedef BtNode *BTree;			//定义BtNode *类型为BTree
//二叉树栈
typedef struct {
	BtNode * stack[MaxNode];	//栈区
	int top;					//栈顶指针
}BTreeStack;

typedef struct {
	BtNode * pNode;
	int height;
}BtNodewithHeight;
//二叉树队列
typedef struct {
	BtNodewithHeight queue[MaxNode];	//队列数据区
	int front;							//队列头指针
	int rear;							//队列尾指针
}BTreeQueue;
//从文件中读取系谱图（以括号表示法储存）
bool ReadfromFile(char *&s) {
	FILE *fp = NULL;
	fopen_s(&fp, fileName, "rb");
	int size = 0;
	if (fp == NULL)
		return false;
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	s = (char *)malloc(sizeof(size + 1));		//在这里分配了内存空间，在外面使用，最后释放
	*(s + size) = '\0';
	fread(s, size, 1, fp);
	fclose(fp);
	return true;
}
//从括号表述法创建二叉树（使用栈进行实现）
bool CreateBTreefromBracketNotation(BTree &r, char * btStr) {
	BTreeStack bts;
	bts.top = -1;						//初始化栈


	int i = 0, k = 0;					//i用于保存串的偏移量，k用于标记处理栈顶的左指针还是右指针
	char ch;						//ch用于保存括号表示法串的字符
	BtNode * temp = NULL;				//temp用于保存待处理的节点
	while ((ch = *(btStr + i)) != '\0')	//循环扫描串，并将字符存到ch
	{
		switch (ch) {
		case '(':					//将子树根节点进栈，准备处理根节点左指针
			bts.stack[++bts.top] = temp;
			k = 1;
			break;
		case ')':					//子树根节点出栈
			bts.top--;
			break;
		case ',':					//准备处理子树根节点右指针
			k = 2;
			break;
		default:					//处理数据节点
			temp = (BtNode *)malloc(sizeof(BtNode));
			temp->data = ch;
			temp->lchild = temp->rchild = NULL;
			switch (k) {
			case 0:
				r = temp;
				break;
			case 1:
				bts.stack[bts.top]->lchild = temp;
				break;
			case 2:
				bts.stack[bts.top]->rchild = temp;
				break;
			}
			break;
		}
		i++;
	}
	return true;
}
//寻找某人的所有孩子函数(递归实现)
//@BTree r表示子树的根节点
//@char e表示要寻找的节点编号
//@bool src储存得到该节点的路径（左还是右） true代表左 false代表右 第一次调用时（即根节点时）src为true
bool FindAllSon(BTree r, char e, bool src) {
	if (r == NULL)											//递归出口
		return false;
	if (r->data == e) {										//找到该人
		BtNode * temp = NULL;
		if (src == true) {										//表示该节点为家族外来人，孩子直接挂在他的右子树上
			temp = r->rchild;
			if (temp == NULL)
				printf("%c没有孩子\n", e);
			else {
				printf("%c的孩子有：\t", e);
				while (temp != NULL) {
					printf("%c\t", temp->data);
					temp = temp->rchild;
				}
				printf("\n");
			}
		}
		else {												//表示该节点为家族内部人，孩子挂在他的配偶身上（即左子树的右子树上）
			if (r->lchild == NULL)
				printf("%c没有配偶，没有孩子\n", e);
			else {
				temp = r->lchild->rchild;
				if (temp == NULL)
					printf("%c还没有孩子\n", e);
				else {
					printf("%c的孩子有：\t", e);
					while (temp != NULL) {
						printf("%c\t", temp->data);
						temp = temp->rchild;
					}
				}
			}
		}
		return true;
	}
	else {
		if (!FindAllSon(r->lchild, e, true))						//寻找左子树
			return FindAllSon(r->rchild, e, false);					//左子树未找到时寻找右子树
		else
			return true;
	}
}
//寻找祖先元素（递归实现）
//@BTree r代表根节点
//@char e代表待寻找的元素编号
//@BTreeStack *bt代表记录节点路径信息的栈
bool FindAllAncestor(BTree r, char e, BTreeStack * bt) {
	if (r == NULL)
		return false;												//递归出口，未找到该节点
	int temp = ++bt->top;											//temp储存根节点进栈后的栈顶指针
	bt->stack[temp] = r;											//将根节点进栈
	if (r->data == e) {												//递归出口，找到该节点,根据路径判断该节点的祖先元素
		if (bt->top == 0)
			printf("%c为该家谱图中的根节点，祖先元素无法找出\n", e);
		else {
			if (bt->stack[bt->top - 1]->lchild == bt->stack[bt->top])
				printf("%c是外来人口，根据该家谱图如法得出其祖先元素\n", e);
			else {
				int k = 0;											//k记录输出祖先元素的对数
				printf("%c的祖先元素有：\t", e);
				for (int i = 0; i < bt->top; i += 2) {
					if (bt->stack[i]->lchild == bt->stack[i + 1]) {
						k++;
						printf("(%c,%c)\t", bt->stack[i]->data, bt->stack[i + 1]->data);
					}
				}
				if (k == 0)
					printf("null\n");
				else
					printf("\n");
			}
		}
		return true;
	}
	else {
		if (!FindAllAncestor(r->lchild, e, bt)) {						//在左子树中找改节点
			bt->top = temp;												//左子树中未找到则退栈
			return FindAllAncestor(r->rchild, e, bt);					//在右子树中寻找该节点
		}
		else
			return true;
	}
}
//以括号表示输出二叉树(递归实现)
void DispbyBracketNotation(BTree r)
{
	if (r != NULL) {
		printf("%c", r->data);
		if (r->lchild != NULL || r->rchild != NULL) {
			printf("(");
			DispbyBracketNotation(r->lchild);
			if (r->rchild != NULL)
				printf(",");
			DispbyBracketNotation(r->rchild);
			printf(")");
		}
	}
}
//求二叉树的高度
int HeightofBTree(BTree r, int h)
{
	int lh = h, rh = h;
	if (r->lchild != NULL)
		lh = HeightofBTree(r->lchild, h + 1);
	if (r->rchild != NULL)
		rh = HeightofBTree(r->rchild, h + 1);
	return lh >= rh ? lh : rh;
}
//输出星号函数
void printStar(int n)
{
	for (int i = 0; i < n; i++)
		printf(" * ");
	printf("\n");
}
//以凹入表示法输出二叉树
void DispbyIndentation(BTree r, BTreeQueue * q)
{
	int h = HeightofBTree(r, 1);		//获得树的总高度

	BtNodewithHeight *p = NULL;

	q->queue[++q->rear].pNode = r;	//根节点进队
	q->queue[q->rear].height = h;

	while (q->front != q->rear) {
		q->front = (q->front + 1) % MaxNode;
		p = &(q->queue[q->front]);
		if (p->pNode != NULL) {
			printf("%c:\t", p->pNode->data);
			printStar(p->height);
			q->queue[++q->rear].pNode = p->pNode->lchild;
			q->queue[q->rear].height = p->height - 1;
			q->queue[++q->rear].pNode = p->pNode->rchild;
			q->queue[q->rear].height = p->height - 1;
		}

	}

}
bool FamilyMemberAdd() {
	return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char familyMapStr[30] = "A(B(,D(G(,I(,J)),H)),C(E,F))";	//树的括号表示法字符串
	BTree bt = NULL;										//树的根节点指针
	BTreeStack bs;											//创建二叉树的栈
	bs.top = -1;											//初始化二叉树栈
	BTreeQueue bq;											//创建二叉树队列
	bq.front = bq.rear = -1;										//初始化二叉树队列
	char a = 'F', b = 'B';
	CreateBTreefromBracketNotation(bt, familyMapStr);		//创建家谱二叉树
	FindAllSon(bt, a, true);									//寻找a变量元素的孩子
	printf("\n");
	if (!FindAllAncestor(bt, b, &bs))						//寻找b变量元素的祖先
		printf("%c的祖先在家谱图中没有得到体现", b);
	printf("\n");
	printf("二叉树的括号表示法如下：\n");
	DispbyBracketNotation(bt);
	printf("\n\n");
	printf("二叉树的凹入表示法如下：\n");
	DispbyIndentation(bt, &bq);
	printf("\n");
	//printf("%d\n",HeightofBTree(bt,1));
	system("PAUSE");
	return 0;
}
