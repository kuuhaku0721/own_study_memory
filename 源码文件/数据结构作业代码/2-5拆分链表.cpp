/*
* һ����ͷ��������A�ֽ�Ϊ��ͬ�ṹ������B������C������B��ֻ��С���������A��ֻ������������BC������A�Ľڵ�
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
	void expliceNode(Node* head)
	{
		//��������
		Node* bNode = (Node*)malloc(sizeof(Node));
		Node* cNode = (Node*)malloc(sizeof(Node));
		Node* p, * endB, * endC;
		endB = bNode;
		endC = cNode;
		head = head->next;
		while (head)
		{
			p = head;
			if (head->data < 0)
			{
				endB->next = p;
				endB = p;
			}
			else
			{
				endC->next = p;
				endC = p;
			}
			head = head->next;
		}
		endB->next = NULL;
		endC->next = NULL;

		bNode = bNode->next;
		while (bNode)
		{
			cout << bNode->data << ' ';
			bNode = bNode->next;
		}
		cout << endl;

		cNode = cNode->next;
		while (cNode)
		{
			cout << cNode->data << ' ';
			cNode = cNode->next;
		}
		cout << endl;
	}
};

void InitNode(Node*& head1)
{
	int ia[10] = { 0,-1,3,-5,7 ,-2,3,-6,7,-9 };
	//��ʼ������
	head1 = (Node*)malloc(sizeof(Node));
	Node* p, * end;
	end = head1;
	for (int i = 0; i < 10; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ia[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;
}

int main()
{
	Node* head1;
	InitNode(head1);
	Solution().expliceNode(head1);

	system("pause");
	return 0;
}

