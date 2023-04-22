#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
/*
* 请先翻到最下面找main函数，start是启动单链表 startS是启动顺序表
* 下面函数，上半部分是单链表，下半部分是顺序表
* 注释都在单链表内，先写的单链表，顺序表是根据单链表改来的，注释不再重复添加
* 穿插使用了一些C语言的函数比如malloc申请内存,相当于new,开辟空间使用，基于C++特性，使用前均需要开辟空间
*/

typedef struct singleList  //单链表
{
	int num;
	struct singleList * next;
}Node;
typedef struct  //顺序表
{
	int nums[5];
	int total;
}SquenList;
/***************************************/
//初始化链表
Node* init()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* head, * node, * end;  //声明一下首尾和过继结点
	head = (Node*)malloc(sizeof(Node));  //C语言的开辟空间，可以用new
	end = head; //链表为空时，头等于尾
	for (int i = 0; i < 10; i++)
	{
		node = (Node*)malloc(sizeof(Node));  //从头指针之后，开辟空间->赋值->移动后继指针->尾指针往后移
		node->num = arr[i];
		end->next = node;
		end = node;
	}
	end->next = NULL; //最后尾指针指向空，代表链表到头

	return head;
}
//清空链表
void clearList(Node* head)
{
	if (head == NULL)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	//加一步确定，不然第一步就清空后续所有操作都没法进行，所以为什么清空是第一个啊kora
	cout << "确定要清空吗？(若此为第一步操作，则后续所有操作皆为空表):" << endl;
	cout << "y--确定" << endl;
	cout << "n--取消" << endl;
	char c;
	cin >> c;
	if (c == 'y')
	{
		//是不清空头节点的，从第一个有数据的节点开始释放
		Node* p = head->next;  //清空链表不是删除链表，链表标志的头指针需要保留
		while (p != NULL)
		{
			//先保存下一个节点的位置
			Node* nextP = p->next;
			free(p);  //C语言的释放内存，可以用delete
			p = nextP; //当前结点往后移动
		}
		//将头结点next指针置空,代表链表的头结点就指向空，同时也是尾结点
		head->next = NULL;
		cout << "清空完成" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "操作取消" << endl;
		system("pause");
		system("cls");
	}
	
}
//判断是否为空
void listEmpty(Node * head)
{
	if (head->next == NULL) //同上
	{
		cout << "链表为空" << endl;
	}
	else
	{
		cout << "链表不为空" << endl;
	}

	system("pause");
	system("cls");
}
//获取链表长度
void listLength(Node* head)
{
	Node* p = head->next; //因为头结点是不存放数据的，所以基本操作都是从head->next开始
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	cout << "链表长度为：" << i << endl;
	system("pause");
	system("cls");
}
int getLength(Node* head)
{
	//同上，只是方便后续需要链表长的操作
	Node* p = head->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
//查找数据
void searchList(Node* head)
{
	cout << "请输入想要查找的位置：" << endl;
	int n;
	cin >> n;
	if (n > 10 || n < 0)
	{
		cout << "位置不合法" << endl;
		system("pause");
		system("cls");
		return;
	}
	Node* p = head->next;
	int i = 0;
	while (p != NULL && i < n)
	{
		p = p->next;  //通过循环查找所需位置
		i++;
	}
	if (p == NULL) //循环一直进行到了链表尾指向了NULL，说明没找到
	{
		cout << "该点不存在" << endl;
	}
	else  //找到值了就会跳出循环
	{
		cout << "索引list[" << n << "]处的值为：" << p->num << endl;
	}

	system("pause");
	system("cls");
}
//求前驱
void beforeList(Node* head)
{
	Node* p = new Node;
	p = head->next;
	//第一个元素的前驱、不存在顺序表中的元素的直接前驱，其他元素的直接前驱
	cout << "第一个元素为：" << p->num << " 其前驱指针为：" << head << endl;
	cout << "请输入想要查找前驱的元素：" << endl;
	int n;
	cin >> n;
	Node* beforeP = new Node;  //需要有一个指针保存当前p的上一个位置
	int i = 0;
	int len = getLength(head);  //循环用当前链表长，防止插入或删除数据之后链表长度改变
	while (p != NULL && i < len)
	{
		if (p->num == n)
		{
			break;
		}
		beforeP = p;
		p = p->next;
		i++;
	}
	if (i == len)
	{
		cout << "数据：" << n << "不在链表内，无前驱" << endl;
	}
	else
	{
		cout << "数据：" << n << " 的前驱指针为：" << beforeP << " 节点处数据为：" << beforeP->num << endl;
	}
	system("pause");
	system("cls");
}
//求后继
void listEnd(Node* head)
{
	//最后一个元素的后继、不存在顺序表中的元素的直接后继，其他元素的直接后继
	Node* p = head->next;
	Node* beforeP = new Node;  //虽然也是当前p的上一个，但是因为是后继，最后一个是没有后继的，所以需要保存最后一个的上一个
	while (p != NULL)
	{
		beforeP = p;
		p = p->next;
	}
	cout << "最后一个元素为：" << beforeP->num << " 其后继指针为：" << beforeP->next << endl;

	cout << "请输入想要查找后继的元素：" << endl;
	int n;
	cin >> n;
	Node* afterP = new Node;  //当前p的下一个，用于输出后继
	int i = 0;
	int len = getLength(head);
	p = head->next;
	while (p != NULL && i < len)
	{
		if (p->num == n)
		{
			afterP = p->next;
			break;
		}
		p = p->next;
		i++;
	}
	if (i == len)
	{
		cout << "数据：" << n << "不在链表内，无后继" << endl;
	}
	else
	{
		cout << "数据：" << n << " 的后继指针为：" << afterP << " 节点处数据为：" << afterP->num << endl;
	}
	system("pause");
	system("cls");
}
//插入数据
void insertList(Node* head)
{
	Node* p = head, *in;
	cout << "请输入想要插入的位置：" << endl;
	int n;
	cin >> n;
	int i = 0;
	while (p != NULL && i < n)  //找到索引位置
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		cout << "结点不存在" << endl;
	}
	else
	{
		in = (Node*)malloc(sizeof(Node));  //insert指针需要提前开辟空间
		cout << "请输入想要插入的数据：" << endl;
		int inNum;
		cin >> inNum;
		in->num = inNum; //赋值
		in->next = p->next; //移动后继指针
		p->next = in; //移动前驱指针
		cout << "插入成功" << endl;
	}

	system("pause");
	system("cls");
}
//删除数据
void deleteList(Node* head)
{
	Node* p = head, * beforeP; //需要提前保存当前结点的上一个结点，删除就是上一个直接指向下一个跳过当前
	beforeP = (Node*)malloc(sizeof(Node));
	cout << "请输入想要删除的位置：" << endl;
	int n;
	cin >> n;
	if (n < 0)
	{
		cout << "输入违法" << endl;
		return;
	}
	int i = -1;
	while (i < n && p != NULL)
	{
		beforeP = p;
		p = p->next;
		i++;
	}
	if (p != NULL)
	{
		beforeP->next = p->next;
		free(p);  //上一个的后继跳过当前直接指向下一个的前驱，然后释放内存
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "结点不存在" << endl;
	}

	system("pause");
	system("cls");
}
//打印输出
void displayList(Node* head)
{
	Node* p = head->next;
	if (p == NULL)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (p != NULL)
	{
		cout << p->num << " ";
		p = p->next;
	}
	puts(""); //换行
	system("pause");
	system("cls");
}
/***************************************/

//初始化链表~~
SquenList* initS()
{
	SquenList* L;
	L = (SquenList*)malloc(sizeof(SquenList));
	//SquenList* L = new SquenList;
	if (L != NULL)
	{
		L->total = 0;
	}

	return L;
}
//清空链表~~
void clearListS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "确定要清空吗？(若此为第一步操作，则后续所有操作皆为空表):" << endl;
	cout << "y--确定" << endl;
	cout << "n--取消" << endl;
	char c;
	cin >> c;
	if (c == 'y')
	{
		head->total = 0;
		cout << "清空完成" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "操作取消" << endl;
		system("pause");
		system("cls");
	}

}
//判断是否为空~~
void listEmptyS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
	}
	else
	{
		cout << "链表不为空" << endl;
	}

	system("pause");
	system("cls");
}
//获取链表长度~~
void listLengthS(SquenList* head)
{
	cout << "链表长度为：" << head->total << endl;
	system("pause");
	system("cls");
}
//查找数据~~
void searchListS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入想要查找的位置：" << endl;
	int n;
	cin >> n;
	if (n > head->total || n < 1)
	{
		cout << "位置不合法或当前没有该数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "位置：" << n << " 处的元素是：" << head->nums[n - 1] << endl;

	system("pause");
	system("cls");
}
//求前驱~~
void beforeListS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "第一个元素为：" << head->nums[0] << " 其前驱指针为：" << head << endl;
	cout << "请输入想要查找前驱的元素：" << endl;
	int n;
	cin >> n;
	int count = head->total;
	for (int i = 0; i < head->total; i++)
	{
		if (head->nums[i] == n)
		{
			count = i;
			break;
		}
	}
	if (count == head->total)
	{
		cout << "该元素不在链表内，无前驱" << endl;
	}
	else
	{
		cout << "数据：" << n << " 的前驱为：" << head->nums[count - 1] << endl;
	}
	system("pause");
	system("cls");
}
//求后继
void listEndS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "最后一个元素为：" << head->nums[head->total-1] << " 其后继为：" << head->nums[head->total] << endl;
	cout << "请输入想要查找后继的元素：" << endl;
	int n;
	cin >> n;
	int count = -1;
	for (int i = 0; i < head->total; i++)
	{
		if (head->nums[i] == n)
		{
			count = i;
			break;
		}
	}
	if (count == -1)
	{
		cout << "该元素不在链表内，无后继" << endl;
	}
	else
	{
		cout << "数据：" << n << " 的后继为：" << head->nums[count + 1] << endl;
	}
	system("pause");
	system("cls");
}
//插入数据~~
void insertListS(SquenList* head)
{
	cout << "请输入想要插入的位置和插入的元素：" << endl;
	int n, num;
	cin >> n >> num;
	if (n < 1 || n > head->total + 1)
	{
		cout << "位置不合法" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = head->total - 1; i >= n-1; i--)
	{
		head->nums[i + 1] = head->nums[i];
	}
	head->nums[n - 1] = num;
	head->total++;
	cout << "插入完成" << endl;

	system("pause");
	system("cls");
}
//删除数据~~
void deleteListS(SquenList* head)
{
	
	cout << "请输入想要删除的位置：" << endl;
	int n;
	cin >> n;
	if (n > head->total || n < 1)
	{
		cout << "位置不合法" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = n; i < head->total; i++)
	{
		head->nums[i - 1] = head->nums[i];
	}
	head->total--;
	cout << "删除完成" << endl;

	system("pause");
	system("cls");
}
//打印输出~~
void displayListS(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < head->total; i++)
	{
		cout << head->nums[i] << " ";
	}
	puts(""); //换行
	system("pause");
	system("cls");
}

//启动界面
void start()
{
	//程序启动先创建一个单链表，保证初始链表不为空
	Node* head = init();
	SquenList* begin = initS();

	while (true)
	{
		cout << "<------------------------------>" << endl;
		cout << "|请输入操作指令：              |" << endl;
		cout << "|顺序表默认空，链表默认非空    |" << endl;
		cout << "|1-----清空线性表              |" << endl;  //清空链表，除头结点以外其余的释放
		cout << "|2-----判断线性表是否为空      |" << endl;
		cout << "|3-----求线性表的长度          |" << endl;
		cout << "|4-----获取线性表指定位置元素  |" << endl;
		cout << "|5-----求前驱                  |" << endl;
		cout << "|6-----求后继                  |" << endl;
		cout << "|7-----在线性表指定位置插入元素|" << endl;
		cout << "|8-----删除线性表指定位置元素  |" << endl;
		cout << "|9-----显示线性表              |" << endl;
		cout << "|      退出,请输入任意一个负数 |" << endl;
		cout << "<------------------------------>" << endl;
		puts(" ");
		cout << "|-----请输入：-----|" << endl;
		int command;
		cin >> command;
		if (command < 0)
		{
			command = -1;
		}
		switch (command)
		{
		case 1:
			clearList(head);
			break;
		case 2:
			listEmpty(head);
			break;
		case 3:
			listLength(head);
			break;
		case 4:
			searchList(head);
			break;
		case 5:
			beforeList(head);
			break;
		case 6:
			listEnd(head);
			break;
		case 7:
			insertList(head);
			break;
		case 8:
			deleteList(head);
			break;
		case 9:
			displayList(head);
			break;
		case -1:
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void startS()
{
	SquenList* begin = initS();

	while (true)
	{
		cout << "<------------------------------>" << endl;
		cout << "|请输入操作指令：              |" << endl;
		cout << "|顺序表默认空，链表默认非空    |" << endl;
		cout << "|1-----清空线性表              |" << endl;
		cout << "|2-----判断线性表是否为空      |" << endl;
		cout << "|3-----求线性表的长度          |" << endl;
		cout << "|4-----获取线性表指定位置元素  |" << endl;
		cout << "|5-----求前驱                  |" << endl;
		cout << "|6-----求后继                  |" << endl;
		cout << "|7-----在线性表指定位置插入元素|" << endl;
		cout << "|8-----删除线性表指定位置元素  |" << endl;
		cout << "|9-----显示线性表              |" << endl;
		cout << "|      退出,请输入任意一个负数 |" << endl;
		cout << "<------------------------------>" << endl;
		puts(" ");
		cout << "|-----请输入：-----|" << endl;
		int command;
		cin >> command;
		if (command < 0)
		{
			command = -1;
		}
		switch (command)
		{
		case 1:
			clearListS(begin);
			break;
		case 2:
			listEmptyS(begin);
			break;
		case 3:
			listLengthS(begin);
			break;
		case 4:
			searchListS(begin);
			break;
		case 5:
			beforeListS(begin);
			break;
		case 6:
			listEndS(begin);
			break;
		case 7:
			insertListS(begin);
			break;
		case 8:
			deleteListS(begin);
			break;
		case 9:
			displayListS(begin);
			break;
		case -1:
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


int main()
{
	//start();
	startS();
	

	system("pause");
	return 0;
}

