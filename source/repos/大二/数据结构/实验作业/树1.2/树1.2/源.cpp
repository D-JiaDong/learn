#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<tchar.h>
#define fileName "familyMap.dat"//����ڵ�������
#define MaxNode 20//�ڵ���������
typedef char ElemType;//�������ڵ�����(�ڵ�����)
typedef struct btnode {
	ElemType data;				//����ͼ����Ա���
	btnode * lchild;			//��Ա����żָ��
	btnode * rchild;			//��Ա����Ů����Ů���ֵ�ָ��
}BtNode;
typedef BtNode *BTree;			//����BtNode *����ΪBTree
//������ջ
typedef struct {
	BtNode * stack[MaxNode];	//ջ��
	int top;					//ջ��ָ��
}BTreeStack;

typedef struct {
	BtNode * pNode;
	int height;
}BtNodewithHeight;
//����������
typedef struct {
	BtNodewithHeight queue[MaxNode];	//����������
	int front;							//����ͷָ��
	int rear;							//����βָ��
}BTreeQueue;
//���ļ��ж�ȡϵ��ͼ�������ű�ʾ�����棩
bool ReadfromFile(char *&s) {
	FILE *fp = NULL;
	fopen_s(&fp, fileName, "rb");
	int size = 0;
	if (fp == NULL)
		return false;
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	s = (char *)malloc(sizeof(size + 1));		//������������ڴ�ռ䣬������ʹ�ã�����ͷ�
	*(s + size) = '\0';
	fread(s, size, 1, fp);
	fclose(fp);
	return true;
}
//�����ű�����������������ʹ��ջ����ʵ�֣�
bool CreateBTreefromBracketNotation(BTree &r, char * btStr) {
	BTreeStack bts;
	bts.top = -1;						//��ʼ��ջ


	int i = 0, k = 0;					//i���ڱ��洮��ƫ������k���ڱ�Ǵ���ջ������ָ�뻹����ָ��
	char ch;						//ch���ڱ������ű�ʾ�������ַ�
	BtNode * temp = NULL;				//temp���ڱ��������Ľڵ�
	while ((ch = *(btStr + i)) != '\0')	//ѭ��ɨ�贮�������ַ��浽ch
	{
		switch (ch) {
		case '(':					//���������ڵ��ջ��׼��������ڵ���ָ��
			bts.stack[++bts.top] = temp;
			k = 1;
			break;
		case ')':					//�������ڵ��ջ
			bts.top--;
			break;
		case ',':					//׼�������������ڵ���ָ��
			k = 2;
			break;
		default:					//�������ݽڵ�
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
//Ѱ��ĳ�˵����к��Ӻ���(�ݹ�ʵ��)
//@BTree r��ʾ�����ĸ��ڵ�
//@char e��ʾҪѰ�ҵĽڵ���
//@bool src����õ��ýڵ��·���������ң� true������ false������ ��һ�ε���ʱ�������ڵ�ʱ��srcΪtrue
bool FindAllSon(BTree r, char e, bool src) {
	if (r == NULL)											//�ݹ����
		return false;
	if (r->data == e) {										//�ҵ�����
		BtNode * temp = NULL;
		if (src == true) {										//��ʾ�ýڵ�Ϊ���������ˣ�����ֱ�ӹ���������������
			temp = r->rchild;
			if (temp == NULL)
				printf("%cû�к���\n", e);
			else {
				printf("%c�ĺ����У�\t", e);
				while (temp != NULL) {
					printf("%c\t", temp->data);
					temp = temp->rchild;
				}
				printf("\n");
			}
		}
		else {												//��ʾ�ýڵ�Ϊ�����ڲ��ˣ����ӹ���������ż���ϣ������������������ϣ�
			if (r->lchild == NULL)
				printf("%cû����ż��û�к���\n", e);
			else {
				temp = r->lchild->rchild;
				if (temp == NULL)
					printf("%c��û�к���\n", e);
				else {
					printf("%c�ĺ����У�\t", e);
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
		if (!FindAllSon(r->lchild, e, true))						//Ѱ��������
			return FindAllSon(r->rchild, e, false);					//������δ�ҵ�ʱѰ��������
		else
			return true;
	}
}
//Ѱ������Ԫ�أ��ݹ�ʵ�֣�
//@BTree r������ڵ�
//@char e�����Ѱ�ҵ�Ԫ�ر��
//@BTreeStack *bt�����¼�ڵ�·����Ϣ��ջ
bool FindAllAncestor(BTree r, char e, BTreeStack * bt) {
	if (r == NULL)
		return false;												//�ݹ���ڣ�δ�ҵ��ýڵ�
	int temp = ++bt->top;											//temp������ڵ��ջ���ջ��ָ��
	bt->stack[temp] = r;											//�����ڵ��ջ
	if (r->data == e) {												//�ݹ���ڣ��ҵ��ýڵ�,����·���жϸýڵ������Ԫ��
		if (bt->top == 0)
			printf("%cΪ�ü���ͼ�еĸ��ڵ㣬����Ԫ���޷��ҳ�\n", e);
		else {
			if (bt->stack[bt->top - 1]->lchild == bt->stack[bt->top])
				printf("%c�������˿ڣ����ݸü���ͼ�編�ó�������Ԫ��\n", e);
			else {
				int k = 0;											//k��¼�������Ԫ�صĶ���
				printf("%c������Ԫ���У�\t", e);
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
		if (!FindAllAncestor(r->lchild, e, bt)) {						//�����������ҸĽڵ�
			bt->top = temp;												//��������δ�ҵ�����ջ
			return FindAllAncestor(r->rchild, e, bt);					//����������Ѱ�Ҹýڵ�
		}
		else
			return true;
	}
}
//�����ű�ʾ���������(�ݹ�ʵ��)
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
//��������ĸ߶�
int HeightofBTree(BTree r, int h)
{
	int lh = h, rh = h;
	if (r->lchild != NULL)
		lh = HeightofBTree(r->lchild, h + 1);
	if (r->rchild != NULL)
		rh = HeightofBTree(r->rchild, h + 1);
	return lh >= rh ? lh : rh;
}
//����Ǻź���
void printStar(int n)
{
	for (int i = 0; i < n; i++)
		printf(" * ");
	printf("\n");
}
//�԰����ʾ�����������
void DispbyIndentation(BTree r, BTreeQueue * q)
{
	int h = HeightofBTree(r, 1);		//��������ܸ߶�

	BtNodewithHeight *p = NULL;

	q->queue[++q->rear].pNode = r;	//���ڵ����
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
	char familyMapStr[30] = "A(B(,D(G(,I(,J)),H)),C(E,F))";	//�������ű�ʾ���ַ���
	BTree bt = NULL;										//���ĸ��ڵ�ָ��
	BTreeStack bs;											//������������ջ
	bs.top = -1;											//��ʼ��������ջ
	BTreeQueue bq;											//��������������
	bq.front = bq.rear = -1;										//��ʼ������������
	char a = 'F', b = 'B';
	CreateBTreefromBracketNotation(bt, familyMapStr);		//�������׶�����
	FindAllSon(bt, a, true);									//Ѱ��a����Ԫ�صĺ���
	printf("\n");
	if (!FindAllAncestor(bt, b, &bs))						//Ѱ��b����Ԫ�ص�����
		printf("%c�������ڼ���ͼ��û�еõ�����", b);
	printf("\n");
	printf("�����������ű�ʾ�����£�\n");
	DispbyBracketNotation(bt);
	printf("\n\n");
	printf("�������İ����ʾ�����£�\n");
	DispbyIndentation(bt, &bq);
	printf("\n");
	//printf("%d\n",HeightofBTree(bt,1));
	system("PAUSE");
	return 0;
}
