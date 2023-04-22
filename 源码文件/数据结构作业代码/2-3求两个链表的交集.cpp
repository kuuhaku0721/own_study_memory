/*
* ����A��B�����������ϣ���A��B�Ľ���,������A��
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
	Node* unionNode(Node* head1, Node* head2)
	{
		Node* p = head1, * t = head1;  //��Ҫ��������ʱ�ڵ���������������������Ȼhead1 = head1->next������ʱ�򷵻ص�Ҳ��NULL
		Node* temp = head2;
		int cnt = 0; //��¼���������ݸ���
		while (t)
		{
			while (temp)
			{
				if (t->data == temp->data)
				{
					p->data = t->data;
					p = p->next;
					cnt++;
				}
				temp = temp->next;
			}
			t = t->next;
			temp = head2;
		}
		cout << "������cnt = " << cnt << endl;
		return head1;
	}
};

void InitNode(Node*& head1, Node*& head2)
{
	int ia[5] = { 0,1,3,5,7 };
	int ib[5] = { 2,3,6,7,9 };
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
	Node* ret = Solution().unionNode(head1->next, head2->next);
	while (ret)
	{
		cout << ret->data << ' ';
		ret = ret->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

