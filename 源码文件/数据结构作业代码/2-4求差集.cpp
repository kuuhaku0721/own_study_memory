/*
* ������������A��B����A��B�Ĳ��A����B��û�У�������ͬ���ķ�ʽ���棬ͬʱ���ظü��ϵ�Ԫ�ظ���
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
	//���ս�����������ʽ����
	Node* differenceNode(Node* head1, Node* head2)
	{
		Node* ret = (Node*)malloc(sizeof(Node));
		Node* end = ret;
		Node* temp = head2;
		while (head1)
		{
			while (temp)
			{
				if (head1->data == temp->data)
				{
					break;
				}
				if (head1->data < temp->data)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL || head1->data < temp->data)
			{
				Node* p = (Node*)malloc(sizeof(Node));
				p->data = head1->data;
				end->next = p;
				end = p;
			}
			head1 = head1->next;
			temp = head2;
		}
		end->next = NULL;
		delete temp;//end��pҪ��Ҫɾ��

		return ret->next;
	}
};

void InitNode(Node*& head1, Node*& head2)
{
	int ia[5] = { 0,2,7,8,10 };
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
	Node* ret = Solution().differenceNode(head1->next, head2->next);
	while (ret)
	{
		cout << ret->data << ' ';
		ret = ret->next;
	}
	cout << endl;

	system("pause");
	return 0;
}



