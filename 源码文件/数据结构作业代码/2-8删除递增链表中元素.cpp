/*
* 删除递增有序链表中值大于mink且小于maxk的所有元素，mink和maxk是给定的两个参数
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
	void deleteminkTomaxk(List*& head, int mink, int maxk)
	{
		List* p = head->next, * beforeP = head;
		while (p)
		{
			if (p->data >= mink && p->data <= maxk)
			{
				beforeP->next = p->next; //符合范围，删除当前p，p移向下一个，但是beforeP不需要动
				free(p);
				p = beforeP->next;
			}
			else
			{
				beforeP = p; //不在范围内，两个指针都要移动
				p = p->next;
			}
			
		}
	}
};

int main()
{
	int ia[10] = { 1,4,3,2,6,0,5,9,7,8 };
	//int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	List* head, * p, * end;
	head = (List*)malloc(sizeof(List));
	end = head;
	for (int i = 0; i < 10; i++)
	{
		p = (List*)malloc(sizeof(List));
		p->data = ia[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;

	Solution().deleteminkTomaxk(head, 3,8); //保有并且传入头结点这样删除方便

	head = head->next;
	while (head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;


	system("pause");
	return 0;
}

