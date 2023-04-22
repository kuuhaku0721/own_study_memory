/*
* �������ǵݼ�����������ϲ�Ϊһ���ǵ�������������������ظ�����ռ�ö���ռ�
* ���Ǻϲ��ҵ�����ݼ�
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
	Node* mergeNode(Node* head1, Node* head2)
	{
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		if (head1->data < head2->data)
		{
			head1->next = mergeNode(head1->next, head2);
			return head1;
		}
		else
		{
			head2->next = mergeNode(head1, head2->next);
			return head2;
		}
		//��������Ҫ���Ǿ��ټ�һ��reverse
	}
};

void InitNode(Node*& head1, Node*& head2)
{
	int ia[5] = { 0,1,3,5,7 };
	int ib[5] = { 2,4,6,8,9 };
	//��ʼ����������
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
}

int main()
{
	Node* head1, * head2;
	InitNode(head1, head2);

	Node* ret = Solution().mergeNode(head1->next, head2->next);
	while (ret)
	{
		cout << ret->data << ' ';
		ret = ret->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

