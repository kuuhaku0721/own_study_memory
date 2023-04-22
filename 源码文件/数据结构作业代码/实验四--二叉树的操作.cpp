/*
*（1）采用二叉链表结构建立二叉树；
*（2）编程实现二叉树的先序、中序、后序和层序遍历；
* (3） 编程实现非递归中序遍历
*（4）编程实现：求二叉树的高度和叶子结点个数；
*/
#include <iostream>
#include <string>
#include<queue>
#include<stack>
using namespace std;

/*定义二叉树的结构*/
typedef struct Node
{
	char data; //数据域
	struct Node* lchild, * rchild; //左子树和右子树
}*BiTree, BiNode;
//整棵树和结点名称

//创建二叉树          创建时传址(修改传址，剩下的不修改传值)
void createBiTree(BiTree &T)
{
	//前序输入，以#结束，一直循环，停止的标志时当前树所有的叶子结点的左右子结点都是空
	//如一个叶子结点就是两个空，三个叶子结点最多六个空
	//画图要更好理解一点
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL; //该结点置空，说明这个分支的父节点是叶子
	}
	else
	{
		T = new BiNode; //不是叶子，也就是不是这个分支最后一个结点，申请空间，赋值
		T->data = ch;
		createBiTree(T->lchild); //有一个内结点就要构建左右子树，如果左右子树都是#，也就是空那就代表它是存有的叶子
		createBiTree(T->rchild);
	}
	//也就是输入的时候要按照树的结构输入，如果直接顺序输入会变成全在左的单侧树
	//输入时按照前序规则根左右的顺序输入，如果是叶子结点就下一个置空输入#
}
//前序遍历
void preOrderTraverse(BiTree T)
{
	/*前中后序遍历只有输出的位置不同*/
	if (T)
	{
		cout << T->data << " ";
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}
}
//中序遍历
void inOrderTraverse(BiTree T)
{
	if (T)
	{
		inOrderTraverse(T->lchild);
		cout << T->data << " ";
		inOrderTraverse(T->rchild);
	}
}
//后序遍历
void postOrderTraverse(BiTree T)
{
	if (T)
	{
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
}
//层序遍历
void floorOrderTraverse(BiTree T)
{
	/*层序遍历一般基于队列实现*/
	queue<BiTree> q;
	if (T != NULL)
	{
		q.push(T); //根结点进队
	}
	while (q.empty() == false)
	{
		BiTree node = q.front();
		cout << node->data << " ";
		if (node->lchild != NULL)
		{
			q.push(node->lchild);
		}
		if (node->rchild != NULL)
		{
			q.push(node->rchild);
		}
		q.pop(); //已经遍历过的出队
	}
}
//非递归中序遍历
void otherInOrderTraverse(BiTree T)
{
	/*非递归利用堆栈实现，遇到一个结点就把它压入栈并遍历左子树
	* 左子树遍历结束后就从栈顶弹出并访问
	* 然后再去访问右子树
	* 非递归实现理解上有点难度，需要好好想
	*/
	if (T == NULL)
	{
		return;
	}
	BiTree bp = T;
	/*构建堆栈*/
	stack<BiTree> s;
	while (bp != NULL || !s.empty())  //注意while的循环条件
	{
		while (bp != NULL)
		{
			s.push(bp);  //第一次遇见入栈
			bp = bp->lchild;  //交给左子树，先输出左子树
		}
		if (!s.empty())
		{
			bp = s.top(); //第二次遇见就输出自己
			cout << bp->data << " ";
			s.pop();
			bp = bp->rchild;  //交给右子树
		}
	}
}
//树高
int treeDepth(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	int i = treeDepth(T->lchild); //递归不能void了，需要返回一个值用以递归
	int j = treeDepth(T->rchild);
	return i > j ? i + 1 : j + 1;
}
//叶子结点数
int leafCount(BiTree T)
{
	if (!T) //不是空，说明不是叶子
	{
		return 0;
	}
	if (!T->lchild && !T->rchild)//叶子+1
	{
		return 1;
	}
	else //内点，返回判断左右孩子
	{
		return leafCount(T->lchild) + leafCount(T->rchild);
	}
}
//启动
void start()
{
	/*建立二叉树*/
	BiTree t;
	cout << "请以前序输入数据以建立二叉树(如ABC###D##，#代表空)：" << endl;
	createBiTree(t);

	/*前中后层序遍历*/ /*测试数据ABC###D## */ // #代表此处为空
	/*效果：
	*              A
	*           B    D
	*          C #  # #
	*         # #
	*/
	cout << "前序遍历：";
	preOrderTraverse(t);

	cout << endl << "中序遍历：";
	inOrderTraverse(t);

	cout << endl << "后序遍历：";
	postOrderTraverse(t);

	cout << endl << "层序遍历：";
	floorOrderTraverse(t);

	cout << endl;
	cout << "非递归中序遍历：";
	otherInOrderTraverse(t);
	cout << endl;

	cout << "树高：" << treeDepth(t) << endl;
	cout << "叶子结点数：" << leafCount(t) << endl;
	
}

int main()
{
	start();

	system("pause");
	return 0;
}

