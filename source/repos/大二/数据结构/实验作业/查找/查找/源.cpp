//#include<iostream>
//using namespace std;
//#define n 30
//int tre[2][n];
//int tre_sum[2*n+2];
////折半查找
//void ef_fine(int num,int l,int r)
//{
//	if(l>r)
//	{
//		cout<<"查找失败";
//		return;
//	}
//	int cen=(l+r)/2;
//	if(num==tre_sum[cen])
//	{
//		cout<<(l+r)/2-1;
//		return;
//	}
//	if(num>tre_sum[cen])
//		ef_fine(num,cen+1,r);
//	else
//		ef_fine(num,l,cen-1);
//}
//int main()
//{
//	for(int i=0;i<2;i++)
//	{
//		cout<<"请输入第"<<i+1<<"个有序序列个数"<<endl;
//		cin>>tre[i][0];
//		for(int j=1;j<=tre[i][0];j++)
//			cin>>tre[i][j];
//	}
//	//俩个有序序列总长
//	tre_sum[0]=tre[0][0]+tre[1][0];
//	int i=1,j=1,k=1;
//	//归并排序
//	while(k<=tre_sum[0])
//	{
//		if(tre[0][i]>tre[1][j])
//		{
//			tre_sum[k]=tre[1][j];
//			j++;
//			k++;
//		}
//		else
//		{
//			tre_sum[k]=tre[0][i];
//			i++;
//			k++;
//		}
//		if(i>tre[0][0])
//		{
//			for(int m=j;m<=tre[1][0];m++)
//				tre_sum[k++]=tre[1][m];
//			break;
//		}
//		if(j>tre[1][0])
//		{
//			for(int m=i;m<=tre[0][0];m++)
//				tre_sum[k++]=tre[0][m];
//			break;
//		}
//	}
//	/*for(int i=0;i<=tre_sum[0];i++)
//		cout<<tre_sum[i]<<' ';*/
//	cout<<"请输入要查找的值"<<endl;
//	int num;
//	cin>>num;
//	ef_fine(num,1,tre_sum[0]);
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	char c;           //字符
	int num;          //次数
	node *L=NULL;     //左子树
	node *R=NULL;     //右子树
};
node nd[100];
char s[100];
bool cmp(node a, node b)
{
	return a.c < b.c;
}
node *root(int l, int r)
{
	if (l > r)
	{
		return NULL;
	}
	if (l == r)
	{
		nd[l].L = NULL;
		nd[l].R = NULL;
		return &nd[l];
	}
	int cen = (l + r) / 2;
	//左右递归求子树根节点
	nd[cen].L = root(l, cen-1);
	nd[cen].R = root(cen+1, r);
	return &nd[cen];
}
int main()
{
	cin >> s;
	int sum = 0;
	//遍历累加求次数
	for (int i = 0; i < strlen(s); i++)
	{
		bool bo = true;
		for (int j = 0; j < sum; j++)
		{
			if (nd[j].c == s[i])
			{
				nd[j].num++;
				bo = false;
				break;
			}
		}
		if (bo)
		{
			nd[sum].c = s[i];
			nd[sum].num = 1;
			sum++;
		}
	}
	//排序
	sort(nd, nd + sum, cmp);
	//递归调用
	*root(0, sum-1);
	//输出
	for (int i = 0; i < sum; i++)
	{
		cout << nd[i].c << '\t';
		cout << "字符出现次数:" << nd[i].num << '\t';
		if (nd[i].L != NULL)
			cout <<"左子树根节点:"<<nd[i].L->c<<'\t';
		else
			cout << "左子树根节点:"<<"空"<<'\t';
		if (nd[i].L != NULL)
			cout << "右子树根节点:" << nd[i].R->c;
		else
			cout << "右子树根节点:" << "空";
		cout << endl;
	}
	system("pause");
	return 0;

}