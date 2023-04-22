/*
* 栈的相关内容
* 建栈，取栈顶元素，入栈，出栈
* 队列相关内容
* 队列，取队头元素，入队，出队。
*/
/*栈与队列均有顺序存储和链式存储两种，首先基于顺序存储实现两种，之后再做链式存储*/
#include <iostream>
#include <string>
#include<cstdlib>
constexpr auto MAX = 5;  //新特性，将运算放在编译阶段而不是运行阶段 define变来的
using namespace std;

/*栈的顺序结构*/
typedef struct
{
	int data[MAX];  //最大容量
	int top;  //栈顶 
}Stack;
//栈的链式结构
typedef struct StackNode
{
	int data;
	struct StackNode* next; //链表结构
}StackNode;
typedef struct StackList
{
	StackNode* top; //栈顶，用链表的存储方式
	int count;  //数量
}StackList;

/*队列的顺序结构*/
typedef struct
{
	int data[MAX];
	int front; //队头
	int rear; //尾指针，若队列不为空，指向队尾下一个元素
}Queue;
//队列的链式存储
typedef struct QueueNode
{
	int data;
	struct QueueNode* next; //链表结构
}QueueNode;
typedef struct
{
	QueueNode* front; //队头指针
	QueueNode* rear; //队尾指针
	int count;
	//比栈好理解一点，就是把队头队尾数据换成了指针，指针隶属于链表结构
}QueueList;

//入栈
void pushOrder(Stack* S)
{
	//数组下标访问，较为好理解
	if (S->top == MAX - 1)//栈满  位置123下标012
	{
		cout << "满栈，无法入栈！" << endl;
		return;
	}
	cout << "请输入入栈数据：" << endl;
	int n;
	cin >> n;

	S->top++;             //栈顶+1（也就是数据长度加1）
	S->data[S->top] = n;  //新元素赋值给栈顶
	cout << "元素：" << n << " 入栈成功" << endl;
	system("pause");
	system("cls");
}
//出栈
void popOrder(Stack* S)
{
	if (S->top == -1)
	{
		cout << "栈为空，无法出栈！" << endl;
		return;
	}
	int num = S->data[S->top]; //拿到栈顶元素
	S->top--;  //栈顶下移（数据长度减1）
	cout << "元素：" << num << " 出栈成功" << endl;
	system("pause");
	system("cls");
}
//获取栈顶
void getTopOrder(Stack* S)
{
	if (S->top == -1)
	{
		cout << "栈为空，无栈顶!" << endl;
	}
	else
	{
		int num = S->data[S->top];
		cout << "当前栈顶为：" << num << endl;
	}
	system("pause");
	system("cls");
}
//查询大小
void inquireOrder(Stack* S)
{
	if (S->top == -1)
	{
		cout << "当前栈为空!" << endl;
	}
	else
	{
		cout << "当前栈大小为：" << S->top + 1 << endl;
		cout << "剩余容量为：" << MAX - S->top - 1 << endl;
	}
	system("pause");
	system("cls");
}
/*栈的顺序存储--启动页面*/
void stackOrder()
{
	//建栈
	Stack* S = new Stack;   //C++ 的new
	//S = (Stack*)malloc(sizeof(Stack));  // C#的malloc  要给空间
	S->top = -1;  //初始化栈顶指针
	
	while (1)
	{
		cout << "************************" << endl;
		cout << "*---当前：栈顺序存储---*" << endl;
		cout << "*                      *" << endl;
		cout << "*请输入想要进行的操作：*" << endl;
		cout << "*1-----入栈            *" << endl;
		cout << "*2-----出栈            *" << endl;
		cout << "*3-----取当前栈顶元素  *" << endl;
		cout << "*4-----查询栈状态      *" << endl;
		cout << "*      按 0 退出       *" << endl;
		cout << "************************" << endl;
		puts("");
		cout << "<----请输入----->" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			pushOrder(S); //入栈
			break;
		case 2:
			popOrder(S); //出栈
			break;
		case 3:
			getTopOrder(S); //取栈顶
			break;
		case 4:
			inquireOrder(S); //查询状态
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


//入队
void enterQueue(Queue* Q)
{
	if ((Q->rear + 1) % MAX == Q->front)
	{
		cout << "当前队列已满!" << endl;
		system("pause");
		system("cls");
		return;
	}
	int n;
	cout << "请输入想要入队的数据：" << endl;
	cin >> n;
	Q->data[Q->rear] = n;  //数据入队
	Q->rear = (Q->rear + 1) % MAX; //更新队尾,注意更新队尾时长度的算法，都是取模
	cout << "入队完成" << endl;
	system("pause");
	system("cls");
}
//出队
void outQueue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		cout << "当前队列为空!" << endl;
		return;
	}
	int n = Q->data[Q->front];  //拿到数据
	Q->front = (Q->front + 1) % MAX; //更新队头

	cout << "数据：" << n << " 已出队" << endl;
	system("pause");
	system("cls");
}
//获取队头
void getTopQueue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		cout << "当前队列为空!" << endl;
		return;
	}
	int n = Q->data[Q->front];  //拿到数据,数组下标访问

	cout << "当前队头数据为：" << n << endl;
	system("pause");
	system("cls");
}
//查询队伍数量
void inquireQueue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		cout << "当前队列为空!" << endl;
		return;
	}
	cout << "当前队伍数量：" << (Q->rear - Q->front + MAX) % MAX << endl;  //注意队伍数量的算法，尾指针减去头指针是当前队伍数，加总数取模是为了获取最终余数才是正确人数，队伍尾进头出，长度随时变化
	int frontNum, backNum;
	frontNum = Q->data[Q->front]; //数组访问就比较容易理解了
	backNum = Q->data[Q->rear - 1];
	cout << "队头是：" << frontNum << endl;
	cout << "队尾是：" << backNum << endl;
	system("pause");
	system("cls");
}
/*队列顺序存储--启动页面*/
void queueOrder()
{
	Queue* Q;   //初始化
	Q = (Queue*)malloc(sizeof(Queue));  //要给空间
	Q->front = 0;  //要赋值
	Q->rear = 0;

	while (1)
	{
		cout << "************************" << endl;
		cout << "*请输入想要进行的操作：*" << endl;
		cout << "*--当前:队列顺序存储---*" << endl;
		cout << "*                      *" << endl;
		cout << "* 1-----入队           *" << endl;
		cout << "* 2-----出队           *" << endl;
		cout << "* 3-----取当前队头元素 *" << endl;
		cout << "* 4-----查询当队列状态 *" << endl;
		cout << "*      按 0 退出       *" << endl;
		cout << "************************" << endl;
		puts("");
		cout << "<----请输入----->" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			enterQueue(Q); //入队
			break;
		case 2:
			outQueue(Q); //出队
			break;
		case 3:
			getTopQueue(Q); //取队头
			break;
		case 4:
			inquireQueue(Q); //查询状态
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

/*
* 由此上，顺序存储
* 由此下，链式存储
*/

//入栈
void pushList(StackList* SL)
{
	cout << "请输入入栈元素：" << endl;
	int num;
	cin >> num;
	StackNode* sn = new StackNode;  //开辟空间
	sn->data = num; //链表加入数据
	sn->next = SL->top; //转换栈顶
	SL->top = sn; //当前结点赋为栈顶  这两步达到效果为 SL->top->data 是当前栈顶数据 SL->top->next 指向下一个数据
	SL->count++; //栈元素加1

	cout << "元素：" << num << " 入栈成功" << endl;
	system("pause");
	system("cls");
}
//出栈
void popList(StackList* SL)
{
	StackNode* sn = new StackNode;
	if (SL->top == NULL)
	{
		cout << "当前栈为空，无法出栈!" << endl;
		return;
	}
	int num = SL->top->data; //拿到栈顶数据
	sn = SL->top;
	SL->top = SL->top->next; //栈顶下移
	delete sn; //释放内存
	SL->count--; //栈元素数量减1

	cout << "元素：" << num << " 出栈成功" << endl;
	system("pause");
	system("cls");
}
//获取栈顶
void getTopList(StackList* SL)
{
	//根据情况void改为返回int 以获得栈顶数据进行进一步运算
	if (SL->top == NULL)
	{
		cout << "当前栈为空，无法出栈!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "当前栈顶为：" << SL->top->data << endl;
	system("pause");
	system("cls");
}
//查询栈状态
void inquireList(StackList* SL)
{
	if (SL->top == NULL)
	{
		cout << "当前栈为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	//栈是不允许跨格访问滴，是不能循环访问全部打印看一遍滴
	cout << "当前栈容量为：" << SL->count << endl;
	system("pause");
	system("cls");
}
/*栈的链式存储--启动页面*/
void stackLink()
{
	//关于栈的链式存储，其实就是在原本的链式存储之上加入链表，让原本是数组存储的元素换成链表存储
	StackList* SL = new StackList; //开辟空间并初始化，不然没法启动
	SL->top = NULL;
	SL->count = 0;
	
	while (1)
	{
		cout << "************************" << endl;
		cout << "*请输入想要进行的操作：*" << endl;
		cout << "*---当前：栈链式存储---*" << endl;
		cout << "*                      *" << endl;
		cout << "* 1-----入栈           *" << endl;
		cout << "* 2-----出栈           *" << endl;
		cout << "* 3-----取当前栈顶元素 *" << endl;
		cout << "* 4-----查询栈状态     *" << endl;
		cout << "*       按 0 退出      *" << endl;
		cout << "************************" << endl;
		puts("");
		cout << "<----请输入----->" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			pushList(SL); //入栈
			break;
		case 2:
			popList(SL); //出栈
			break;
		case 3:
			getTopList(SL); //取栈顶
			break;
		case 4:
			inquireList(SL); //查询状态
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


//入队
void enterQueueList(QueueList* QL)
{
	cout << "请输入想要入队的元素：" << endl;
	int num;
	cin >> num;
	QueueNode* qn = new QueueNode;  //都要提前开辟空间
	qn->data = num; //保存数据
	qn->next = NULL;    //入队进队尾，下一个是空
	QL->rear->next = qn; //转移队尾
	QL->rear = qn;
	QL->count++; //队伍总数加1

	cout << "元素：" << num << " 入队成功" << endl;
	system("pause");
	system("cls");
}
//出队
void outQueueList(QueueList* QL)
{
	QueueNode* qn;
	if (QL->front == QL->rear)
	{
		cout << "当前队列为空!" << endl;
		system("pause");
		system("cls");
		return;
	}
	qn = QL->front->next; //队头暂存，等会删除
	int num = qn->data; //拿到队头数据
	QL->front->next = qn->next; //将原结点的下一个赋给头结点的下一个
	if (QL->rear == qn)
	{
		QL->rear = QL->front; //如果队头就是队尾，删除后让rear指向头
	}
	delete qn;
	QL->count--; //队伍总数减1

	cout << "元素：" << num << " 出队成功" << endl;
	system("pause");
	system("cls");
}
//获取队头
void getTopQueueList(QueueList* QL)
{
	if (QL->front == QL->rear)
	{
		cout << "当前队列为空!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//视情况可以返回int以作后续运算
	cout << "当前队头为：" << QL->front->next->data << endl; //入队的时候是将队尾的next指向新插入，然后将新插入赋给队尾，也就是说head没有存值
	system("pause");
	system("cls");
}
//查询队伍状态
void inquireQueueList(QueueList* QL)
{
	if (QL->front == QL->rear)  //头等于尾即为空
	{
		cout << "当前队列为空!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "队伍总数：" << QL->count << endl;
	cout << "当前队头为：" << QL->front->next->data << endl; //链式存储，也就是链表，head不存数，head->next开始
	cout << "当前队尾为：" << QL->rear->data << endl;
	system("pause");
	system("cls");
}
/*队列的链式存储--启动页面*/
void queueLink()
{
	QueueList* QL = new QueueList;
	QL->front = QL->rear = new QueueNode; //初始化队头队尾，需要初始化，不然没法启动
	QL->rear->next = NULL; //队尾指向空
	QL->count = 0;

	while (1)
	{
		cout << "************************" << endl;
		cout << "*请输入想要进行的操作：*" << endl;
		cout << "*--当前:队列链式存储---*" << endl;
		cout << "*                      *" << endl;
		cout << "* 1-----入队           *" << endl;
		cout << "* 2-----出队           *" << endl;
		cout << "* 3-----取当前队头元素 *" << endl;
		cout << "* 4-----查询当队列状态 *" << endl;
		cout << "*      按 0 退出       *" << endl;
		cout << "************************" << endl;
		puts("");
		cout << "<----请输入----->" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			enterQueueList(QL); //入队
			break;
		case 2:
			outQueueList(QL); //出队
			break;
		case 3:
			getTopQueueList(QL); //去队头
			break;
		case 4:
			inquireQueueList(QL); //查询状态
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


//总的启动页面
void start()
{
	//此工程最好是分开.cpp和.h来写，但是实验文件分文件太多并不好找，因此全部集中在一个cpp文件中
	while (1)
	{
		cout << "**********************" << endl;
		cout << "*请选择启动项目:     *" << endl;
		cout << "* 1----顺序存储--栈  *" << endl;
		cout << "* 2----顺序存储--队列*" << endl;
		cout << "* 3----链式存储--栈  *" << endl;
		cout << "* 4----链式存储--队列*" << endl;
		cout << "*      按 0 退出     *" << endl;
		cout << "**********************" << endl;
		puts("");
		cout << "<----请输入---->" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			system("cls");
			stackOrder(); //顺序栈的启动页面
			break;
		case 2:
			system("cls");
			queueOrder(); //顺序队列的启动页面
			break;
		case 3:
			system("cls");
			stackLink(); //链式栈的启动页面
			break;
		case 4:
			system("cls"); //链式队列的启动页面
			queueLink();
			break;
		case 0:
			cout << "退出成功" << endl;
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


int main()
{
	start();

	system("pause");
	return 0;
}

