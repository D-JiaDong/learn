#include <iostream>
using namespace std;
const int QueueSize = 100; //100是示例性数据，根据需要重新定义
template <typename DataType> //定义模板类CirQueue
class CirQueue
{
public:
	CirQueue(); //构造函数，初始化空队列
	~CirQueue(); //析构函数
	void EnQueue(DataType x); //入队操作，将元素x入队
	DataType DeQueue(); //出队操作，将队头元素出队
	DataType GetQueue(); //取队头元素（并不删除）
	void PrintQueue();
	int Empty(); //判断队列是否为空
private:
	DataType data[QueueSize]; //存放队列元素的数组
	int front, rear; //游标，队头和队尾指针
};

template <typename DataType>
CirQueue<DataType> ::CirQueue()
{
	rear = front = QueueSize - 1;
}

template <typename DataType>
CirQueue<DataType> :: ~CirQueue()
{

}

template <typename DataType>
void CirQueue<DataType> ::EnQueue(DataType x)
{
	if ((rear + 1) % QueueSize == front)
		throw "上溢";
	rear = (rear + 1) % QueueSize; //队尾指针在循环意义下加1
	data[rear] = x; //在队尾处插入元素
}

template <typename DataType>
DataType CirQueue<DataType> ::DeQueue()
{
	
	if (rear == front) throw "下溢";
	front = (front + 1) % QueueSize; //队头指针在循环意义下加1
	return data[front]; //读取并返回出队前的队头元素
}

template <typename DataType>
DataType CirQueue<DataType> ::GetQueue()
{
	if (rear == front) throw "下溢";
	return data[(front + 1) % QueueSize]; //注意不修改队头指针
}


template <typename DataType>
void CirQueue<DataType> ::PrintQueue()
{
	if (rear == front) throw "下溢";
	for (int i = (front + 1) % QueueSize; i <= rear; i++)
		cout << data[i]<<" ";
	cout << endl;
}

template <typename DataType>
int CirQueue<DataType> ::Empty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int main()
{
	int ch;
	CirQueue<int> jz;
	cout << "请选择您要进行的操作：" << endl;
	cout << "（1）排队     （2）就诊" << endl << "（3）查看排队 （4）不在排队" << endl << "（5）下班" << endl;
	while (1)
	{
		cin >> ch;
		if (ch == 1)
		{
			cout << "请输入排队病人的病历号：";
			int  binghao;
			int c = ' ';
			int x = 0;
			while (c != '\n')
			{
				cin >> binghao;
				jz.EnQueue(binghao);
				c = getchar();
			}
			cout << "病人已排队完成" << endl;
		}
		else
			if (ch == 2)
			{
				jz.DeQueue();
				cout << "当前病人就诊完成" << endl;
			}
			else
				if (ch == 3)
				{
					cout << "查看排队：";
					jz.PrintQueue();
				}
				else
					if (ch == 4)
					{
						cout << "当前队列：";
						jz.PrintQueue();
						system("pause");
						return 0;
					}
					else
						if (ch == 5)
						{
							system("pasue");
							return 0;
						}
						else
							cout << "无该选项。。。" << endl;
	}
	system("pause");
	return 0;
}

