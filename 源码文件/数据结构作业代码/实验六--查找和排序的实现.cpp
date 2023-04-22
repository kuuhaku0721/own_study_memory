/*
* （1）编程实现两种查找方法：二分查找和二叉排序树；
*	若查找成功，返回元素在有序数组中的位置和查找次数；
*	若查找失败，返回出错标志和查找次数。
* （2）从课本中选择两种排序算法进行编程实现。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
//二叉树的结构
typedef struct BiNode
{
	int data;
	struct BiNode* lchild, * rchild;
	BiNode(int val) : data(val), lchild(NULL), rchild(NULL) {} //构造,直接创建结点
}BiNode, *BiTree;
//链表结构
typedef struct  //顺序表
{
	int nums[10];
	int total;
}SquenList;

/*二分查找*/
void binarySearch(int arr[], int len, int key)
{
	/*要求原数组必须有序*/
	int left, right, mid = 0;
	left = 0;  //左指针定义在数组最左侧
	right = len - 1; //右指针定义在最右侧
	int cnt = 0; //记录查找次数
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (key < arr[mid])  //当前值比key大，说明要找的在左侧
		{
			right = mid - 1;  //减一是不用再比arr[mid]了
			cnt++;
		}
		else if(key > arr[mid]) //说明在右侧
		{
			left = mid + 1;  //加一同上
			cnt++;
		}
		else  //说明当前mid值就是要找的
		{
			cout << "查找元素：" << key << " 在数组中位置为：" << mid + 1 << endl
				<< "当前查找次数为：" << cnt << endl;
			return; //查找完毕，结束该方法
		}
	}
	//程序运行到这里说明没找到key
	cout << "在数组中未查到：" << key << endl
		<< "当前查找次数：" << cnt << endl;
}
void binary()
{
	int arr[10] = { 1,16,24,35,47,59,62,73,88,99 }; //给定的数组
	int len = 10;  //数组长度
	int key = 62;  //要查的数据
	cout << "当前查找：" << key << endl;
	binarySearch(arr, len, key);

	system("pause");
	system("cls");
	return;
}


/*二叉树查找*/
BiTree SearchBST(BiTree T, int key, int& cnt) 
{
	if (T == NULL || key == T->data)  //如果找到空或找到数据则查找过程结束
	{
		return T;   //查找结束这一次是没有计数的，最终查找次数输出时+1
	}
	if (key < T->data)   //二叉排序树，结点左侧一定比它小，右侧一定比它大，分开去左右子树再度查找
	{
		return SearchBST(T->lchild, key, ++cnt);  //递归查找
	}
	else
	{
		return SearchBST(T->rchild, key, ++cnt);
	}
}
//以插入方式创建二叉排序树
bool InsertBST(BiTree& T, int val) 
{
	if (T == NULL) {
		T = new BiNode(val);  //创建结点，递归创建树结构
		return true;
	}
	if (val == T->data)
	{
		return false;
	}
	if (val < T->data)
	{
		return InsertBST(T->lchild, val);
	}
	else
	{
		return InsertBST(T->rchild, val);
	}
}
void binarySortTree()
{
	//插入顺序直接影响后续整个树的结构
	int arr[10] = { 62,88,58,47,35,73,51,99,37,93 };  //二叉树永远的重点！！！插入顺序
	//创建表
	BiTree T = NULL;   //先置空，等同于开辟空间，没有初值不能跑
	for (int i = 0; i < 10; i++)
	{
		InsertBST(T, arr[i]);  //用一个个插入的方式创建一个树结构
	}
	int key = 93; /*这个是要查找的树，测试功能实验，不做自定义输入*/
	cout << "查找key:" << key << "：" << endl;
	int cnt = 0; //记忆查找次数
	BiTree p = SearchBST(T, key, cnt); //参数：树，要查的key，查找次数
	if (p != NULL)
	{
		cout << "已找到数据：" << key << " :::: (" << p  << ") -> " << p->data << endl;
		cout << "当前查找次数：" << cnt + 1 << endl;
	}
	else
	{
		cout << "未找到"  << key << "，当前查找次数：" << cnt + 1 << endl;//+1因为如果最后一次找到了，那就直接返回了，cnt没有再++
	}

	system("pause");
	system("cls");
	return;
		
}


/*希儿排序*/
void ShellSort(SquenList* &head)  //针对于顺序表
{
	int i, j, k;
	int increment = head->total; //增量
	do
	{
		increment = increment / 3 + 1;               //增量序列
		for ( i = increment+1; i <= head->total; i++)
		{
			if (head->nums[i] < head->nums[i - increment])
			{
				head->nums[0] = head->nums[i];  //第一个位置的0其实是没有数的，第一个位置用来交换数据时暂存数据使用
				for (j = i - increment; j > 0 && head->nums[0] < head->nums[j]; j -= increment)
				{
					head->nums[j + increment] = head->nums[j]; //记录后移，查找插入位置
				}
				head->nums[j + increment] = head->nums[0];  //插入数据
			}
		}
	} while (increment > 1);
}
//初始化链表
SquenList* init()
{
	SquenList* L;
	L = (SquenList*)malloc(sizeof(SquenList));
	if (L != NULL)
	{
		L->total = 0;
	}

	return L;
}
//插入数据
void insertList(SquenList* head, int n, int num)
{
	for (int i = head->total - 1; i >= n - 1; i--) //默认表是写死的，默认数据正确，不再做判断
	{
		head->nums[i + 1] = head->nums[i];
	}
	head->nums[n - 1] = num;
	head->total++;
}
//打印输出
void displayList(SquenList* head)
{
	if (head->total == 0)
	{
		cout << "链表为空" << endl;
		system("pause");
		system("cls");
		return;
	}     //i=1    0处暂存位不予输出
	for (int i = 1; i < head->total; i++)
	{
		cout << head->nums[i] << " ";
	}
	puts(""); //换行
}
void seeleSort()
{
	int arr[10] = { 0,9,1,5,8,3,7,4,6,2 };  //第一个0不是排序的0，是占位用的，第一个是交换暂存位
	SquenList* head = init();  //初始化
	for (int i = 0; i < 10; i++)
	{
		insertList(head, i + 1, arr[i]);  //用插入的方式构造链表
	}
	cout << "排序前：";  //打印输出时默认忽略第一个数，因为那个是暂存位
	displayList(head);

	//排序
	ShellSort(head);

	cout << "排序后：";
	displayList(head);

	system("pause");
	system("cls");
	return;
}


/*快速排序*/
void swap(SquenList* L, int begin, int end)
{
	//交换两个位置的数据
	int temp = L->nums[begin];
	L->nums[begin] = L->nums[end];
	L->nums[end] = temp;
}
int Partition(SquenList* L, int low, int high)
{
	/*交换顺序表L的子表的记录，使枢轴记录到位，并返回其所在位置，此时在它之前均不大于它，在它之后均不小于它*/
	int pivotkey;

	pivotkey = L->nums[low]; //用子表的第一个记录作枢轴记录
	while (low < high)		//从两端交替向中间扫描
	{
		while (low < high && L->nums[high] >= pivotkey)
		{
			high--;
		}
		swap(L, low, high); //将比枢轴小的交换到低端
		while (low < high && L->nums[low] <= pivotkey)
		{
			low++;
		}
		swap(L, low, high); //比枢轴大的交换到高端
	}
	return low;  //返回枢轴所在位置
}
void QSort(SquenList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		//将L->nums[]  一分为二，算出中枢值pivot
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);  //递归调用
		QSort(L, pivot + 1, high);
	}
}
void QuickSort(SquenList* L)
{
	QSort(L, 0, L->total - 1);  //从下标的0-8开始
}
//打印输出
void displayList2(SquenList* L)
{
	for (int i = 0; i < L->total; i++)
	{
		cout << L->nums[i] << " ";
	}
	puts(""); //换行
}
void quickSort()
{
	int arr[9] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 }; //准备数据
	SquenList* L = init();  //初始化
	for (int i = 0; i < 9; i++)
	{
		insertList(L, i + 1, arr[i]);
	}
	cout << "排序前：";
	displayList2(L);

	//排序
	QuickSort(L);

	cout << "排序后：";
	displayList2(L);

	system("pause");
	system("cls");
	return;
}

void start()
{
	while (true)
	{
		cout << "      请选择：    " << endl;
		cout << "查找：" << endl;
		cout << "    1----二分查找" << endl;
		cout << "    2----二叉排序树查找" << endl;
		cout << "排序：" << endl;
		cout << "    3----希儿排序" << endl;
		cout << "    4----快速排序" << endl;
		cout << "其余任意键退出" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1: //二分
			binary();
			break;
		case 2: //二叉排序树
			binarySortTree();
			break;
		case 3: //希儿排序
			seeleSort();
			break;
		case 4: //快速排序
			quickSort();
			break;
		default:
			cout << "已退出" << endl;
			return;
		}
	}
}


/*main函数内只留一个启动接口，方便其他函数的启动统一管理*/
int main()
{
	start();

	system("pause");
	return 0;
}

