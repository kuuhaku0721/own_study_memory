/*
* 已知f是单链表的表头指针，链表存int，以递归方式求1：链表中的最大整数 2：链表的节点个数 3：所有整数的平均值
*/
#include <iostream>
#include <string>
using namespace std;
struct List
{
	int data;
	List* next;
};

class Solution
{
public:
	int maxNum(List* f)
	{
		if (!f)
		{
			return -1;
		}
		int t = maxNum(f->next);
		if (f->data >= t)
		{
			return f->data;
		}
		else {
			return t;
		}
	}

	int nodeNum(List* f)
	{
		if (f)
		{
			return nodeNum(f->next) + 1;
		}
		else
		{
			return 0;
		}
	}

	float avgNode(List* f)
	{
		float sum = sumNode(f);
		int num = nodeNum(f);
		return sum / num;
	}
	int sumNode(List* f)
	{
		if (f)
		{
			return f->data + sumNode(f->next);
		}
		else {
			return 0;
		}
	}
};

int main()
{
	int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	List* f, * p, * end;
	f = (List*)malloc(sizeof(List));
	end = f;
	for (int i = 0; i < 10; i++)
	{
		p = (List*)malloc(sizeof(List));
		p->data = ia[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;

	int maxNum = Solution().maxNum(f->next);
	int nodeNum = Solution().nodeNum(f->next);
	float avgNode = Solution().avgNode(f->next);

	cout << maxNum << ' ' << nodeNum << ' ' << avgNode << ' ' << endl;

	system("pause");
	return 0;
}

