/*
* ���һ���㷨�������������н������ӷ���ԭ�ء���ת����Ҫ�������ԭ��Ĵ洢�ռ䣬���仰˵��Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
*/
#include <iostream>
#include <string>
using namespace std;

typedef struct SingleLink
{
	int data;
	struct SingleLink* next;
}Node;

Node* initLink()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* head, * p, * end;
	head = new Node;
	end = head;
	for (int i = 0; i < 10; i++)
	{
		p = new Node;
		p->data = arr[i];
		end->next = p;
		end = p;
	}
	end->next = NULL;

	return head;
}

void test01()
{
	Node* head = initLink();
	Node* p1 = head->next;
	while (p1)
	{
		cout << p1->data << " ";
		p1 = p1->next;
	}
	cout << endl;

	//r = p  p = q  q = q->next  ���ӵ�һ����ʼ���������ƶ����ǵ�һ�������ǵ��ڵ���ʽ���ڶ�������Ҳ�ǵ��ڵ���ʽ��
	//���������ƾ���next��ʽ��Ȼ���ƶ�ָ��ָ���õڶ���ָ��ָ���һ����p->next = r�� 
	//ע��������ƶ�λ�ã�Ȼ�����ָ�򣬲�Ҫ����ָ���ȥ�ƶ�ָ�룬����һ�������ƶ��������λ�ã�Ȼ���ָ��
	Node* p, * q, * r;
	p = NULL;  //pΪͷ�ڵ�֮ǰ�Ľڵ�
	q = head;  //��qָ������ͷ�����α�ʹ��
	while (q != NULL) 
	{
		r = p;
		p = q;
		q = q->next;
		p->next = r;  //pre�ӵ�֮ǰ�Ľڵ� 
	}
	//������Ϻ�q��������һ�����
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}

