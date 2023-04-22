/*
* 将两个递增的有序链表合并为一个递增的有序链表。
* 要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。
*/
#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

class Solution
{
public:
	Node* mergeNodes(Node* head1, Node* head2)
	{
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		if (head1->data < head2->data)
		{
			head1->next = mergeNodes(head1->next, head2);
			return head1;
		}
		else
		{
			head2->next = mergeNodes(head1, head2->next);
			return head2;
		}
	}
};


int main()
{
	int ia[5] = { 0,1,3,5,7 };
	int ib[5] = { 2,4,6,8,9 };
	Node* head1, * head2;
	//初始化两个链表
	head1 = (Node*)malloc(sizeof(Node));
	Node* p, * end;
	end = head1;
	for (int i = 0; i < 5; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ia[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;

	head2 = (Node*)malloc(sizeof(Node));
	end = head2;
	for (int i = 0; i < 5; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ib[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;

	Node* ret = Solution().mergeNodes(head1->next, head2->next);
	while (ret)
	{
		cout << ret->data << ' ';
		ret = ret->next;
	}
	cout << endl;


	system("pause");
	return 0;
}

