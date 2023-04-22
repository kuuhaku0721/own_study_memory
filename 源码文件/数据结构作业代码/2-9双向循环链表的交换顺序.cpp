#include <iostream>
#include <string>
using namespace std;
struct biList
{
	int data;
	biList* prev;
	biList* next;
};

class Solution
{
public:
	void changeBiList(biList*& head, int index)
	{
		biList* p = head;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		//现在的p就是想要交换的位置的节点，要拿p和它前面的一个交换
		biList* beforeP = p->prev;
		beforeP->prev->next = p;
		p->prev = beforeP->prev;
		beforeP->prev = p;
		beforeP->next = p->next;
		p->next->prev = beforeP;
		p->next = beforeP;
	}
};

int main()
{
	//双向循环链表的搭建
	int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	biList* head, * p, * end;
	head = (biList*)malloc(sizeof(biList));
	head->data = ia[0];
	end = head;
	for (int i = 1; i < 10; i++)
	{
		p = (biList*)malloc(sizeof(biList));
		p->data = ia[i];
		p->prev = end;
		end->next = p;
		end = p;
	}
	end->next = head;
	head->prev = end;
	
	//这里确定一个参数为想要交换的位置
	Solution().changeBiList(head, 6);

	int i = 0;
	while (i < 20)
	{
		cout << head->data << ' ';
		head = head->next;
		i++;
		if (i % 10 == 0) cout << endl;
	}

	system("pause");
	return 0;
}

