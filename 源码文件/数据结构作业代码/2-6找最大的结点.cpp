/*
* ���һ���㷨��ͨ��һ�˱���ȷ������Ϊn�ĵ�������ֵ���Ľ��
*/
#include <iostream>
#include <string>
using namespace std;

typedef struct SingleLink
{
	int data; //������
	struct SingleLink* next; //ָ����
}Node;

//��ʼ��һ������
Node* initLink()
{
	int arr[10] = { 3,1,2,4,5,9,8,6,7,0 };
	Node* head = new Node;
	Node* p, * end;
	end = head;
	int i = 0;
	while (i < 10)
	{
		p = new Node;
		p->data = arr[i];
		end->next = p;
		end = p;
		i++;
	}
	end->next = NULL;

	return head;
}

void test01()
{
	Node* head = initLink();

	int max, index = 0; //��¼���ֵ�����ݣ�����λ��
	Node* p = head->next;
	max = p->data;
	int i = 0;
	while (p)
	{
		i++;
		if (p->data >= max)
		{
			max = p->data;
			index = i;
		}
		p = p->next;
	}
	cout << "����������Ԫ���ǣ�" << max << " �ǵ�" << index << "��Ԫ��" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}

