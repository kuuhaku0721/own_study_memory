#include <iostream>
#include <string>
#include<cstdlib>
#include<vector>
using namespace std;

typedef struct List
{
	int num;
	struct List* next;
}Node;
//用一个类来统一管理  .h
class SingleListOperation
{
public:
	SingleListOperation(); //构造
	void buildList(); //初始化
	void searchList(); //查找
	void insertList(); //插入
	void deleteList(); //删除
	void displayList(); //打印输出
	Node* unionList(Node* list1, Node* list2); //合并
	void mergeTwoList();
private:
	Node* head;
};
/*  .hpp   */
//构造
SingleListOperation::SingleListOperation()
{
	cout << "默认提供初始链表：0，1，2，3，4，5，6，7，8，9" << endl;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* node, * end;
	head = (Node*)malloc(sizeof(Node));
	end = head;
	for (int i = 0; i < 10; i++)
	{
		node = (Node*)malloc(sizeof(Node));
		node->num = arr[i];
		end->next = node;
		end = node;
	}
	end->next = NULL;
}
//初始化
void SingleListOperation::buildList()
{
	cout << "----使用自定义数据初始化----" << endl;
	cout << "请确定数据个数：" << endl;
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	Node* node, * end;
	head = (Node*)malloc(sizeof(Node));
	end = head;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		node = (Node*)malloc(sizeof(Node));
		node->num = *it;
		end->next = node;
		end = node;
	}
	end->next = NULL;

	cout << "创建完成" << endl;
	system("pause");
	system("cls");
}
//查找
void SingleListOperation::searchList()
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
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		cout << "该点不存在" << endl;
	}
	else
	{
		cout << "索引list[" << n << "]处的值为：" << p->num << endl;
	}
	system("pause");
	system("cls");
}
//插入
void SingleListOperation::insertList()
{
	Node* p = head, * in;
	cout << "请输入想要插入的位置：" << endl;
	int n;
	cin >> n;
	int i = 0;
	while (p != NULL && i < n)
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
		in = (Node*)malloc(sizeof(Node));
		cout << "请输入想要插入的数据：" << endl;
		int inNum;
		cin >> inNum;
		in->num = inNum;
		in->next = p->next;
		p->next = in;
		cout << "插入成功" << endl;
	}
	system("pause");
	system("cls");
}
//删除
void SingleListOperation::deleteList()
{
	Node* p = head, * beforeP;
	beforeP = (Node*)malloc(sizeof(Node));
	cout << "请输入想要删除的位置：" << endl;
	int n;
	cin >> n;
	if (n < 0)
	{
		cout << "输入违法" << endl;
		system("pause");
		system("cls");
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
		free(p);
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "结点不存在" << endl;
	}
	system("pause");
	system("cls");
}
//打印
void SingleListOperation::displayList()
{
	Node* p = head->next;
	if (p == NULL)
	{
		cout << "链表为空" << endl;
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
//合并两个有序单链表
Node* SingleListOperation::unionList(Node* list1, Node* list2)
{
	if (list1 == NULL)
	{
		return list2; //如果1为空说明1处理完了只剩2了
	}
	else if (list2 == NULL)
	{
		return list1; //如果2为空说明2处理完了只剩1了
	}
	else if (list1->num < list2->num) //默认升序，所以如果1的num小于2的，1继续下一个，2不动
	{
		list1->next = unionList(list1->next, list2);
		return list1;
	}
	else  //如果1的num大于2的，2继续下一个，1不动
	{
		list2->next = unionList(list1, list2->next);
		return list2;
	}
}
void SingleListOperation::mergeTwoList()
{
	//先准备两个单链表
	int arr1[5] = { 1,3,6,7,8 };
	int arr2[5] = { 2,4,5,9,10 };
	Node* list1, * list2, * node, * end;
	list1 = new Node;
	end = list1;
	//分别初始化两个链表
	for (int i = 0; i < 5; i++)
	{
		node = new Node;
		node->num = arr1[i];
		end->next = node;
		end = node;
	}
	end->next = NULL;

	list2 = new Node;
	end = list2;
	for (int i = 0; i < 5; i++)
	{
		node = new Node;
		node->num = arr2[i];
		end->next = node;
		end = node;
	}
	end->next = NULL;

	cout << "合并前两链表值：" << endl << "链表1：";
	Node* p1 = list1->next;
	Node* p2 = list2->next;
	while (p1)
	{
		cout << p1->num << " ";
		p1 = p1->next;
	}
	cout << endl << "链表2：";
	while (p2)
	{
		cout << p2->num << " ";
		p2 = p2->next;
	}
	//通过参数传递，用递归处理，返回合并后链表
	Node* merge = new Node;
	merge = unionList(list1->next, list2->next);
	//打印最终结果
	cout << endl << "合并后：";
	while (merge)
	{
		cout << merge->num << " ";
		merge = merge->next;
	}
	cout << endl;

	system("pause");
	system("cls");
}

/*  .cpp  */
//启动
void start()
{
	SingleListOperation list;

	while (1)
	{
		cout << "<----------------------->" << endl;
		cout << "请输入想要进行的操作：" << endl;
		cout << "1--------创建" << endl;
		cout << "2--------查找" << endl;
		cout << "3--------插入" << endl;
		cout << "4--------删除" << endl;
		cout << "5--------打印" << endl;
		cout << "6--------两个有序单链表的归并" << endl;
		cout << "         按 0 退出" << endl;
		cout << "<----------------------->" << endl;
		puts("");
		cout << "-------请输入：-------" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1: //创建
			list.buildList();
			break;
		case 2: //查找
			list.searchList();
			break;
		case 3: //插入
			list.insertList();
			break;
		case 4: //删除
			list.deleteList();
			break;
		case 5: //打印输出
			list.displayList();
			break;
		case 6: //合并有序链表
			list.mergeTwoList();
			break;
		case 0:
			cout << "退出成功" << endl;
			return;
		default:
			cout << "输入有错，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

int main()
{
	start(); //main函数只放一个启动界面

	system("pause");
	return 0;
}

