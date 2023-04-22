/*
* �����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���βԪ�ؽڵ㣨����ͷָ�룩
* �Ա�д��Ӧ���ÿն��У��ж϶����Ƿ�Ϊ�գ���Ӻͳ��ӵ��㷨
*/
#include <iostream>
#include <string>
using namespace std;
/*��������ʵӦ�û���ѭ���������������ͷָ�룬��ô��һ���ڵ�ҲҪ�����ݣ����һ��βָ���һ������һ��ͷ������*/
//���ȿ϶���Ҫ����һ��ѭ������--βָ��ָ��ͷ���,Ĭ�����ݶ����ó�0��
typedef struct cycleLink
{
	int data; //������
	struct cycleLink* next; //ָ����
}cycleLink;
class cyNode
{
public:
	cyNode(); //��ʼ��
	bool is_Empty(); //�ж��Ƿ�Ϊ��
	bool is_Fullfill(); //�ж��Ƿ�����
	void En_Queue(); //���
	void De_Queue(); //����

private:
	cycleLink* head; //ͷ���,Ҫ�����ݵ�
	cycleLink* rear; //βָ�룬ֻ�Ǹ�ָ��
	const int none = 65535;
};
cyNode::cyNode()
{
	//�ڹ��캯����ʼ��ʱҪ���ѭ������Ĺ���
	cycleLink* end = new cycleLink;
	//ͷ��㲻�ܶ���֮����л�Ҫ�����
	head = new cycleLink;
	head->data = none;
	end = head;
	cycleLink* p;
	for (int i = 1; i < 10; i++)
	{
		p = new cycleLink;
		p->data = none;
		end->next = p;
		end = p;
	}
	end->next = head;	//ѭ����ϣ���βָ��ָ��ͷ���
	rear = head; //�ö�β��λ,���ڶ�β���ڶ�ͷ

	//ѭ�����������ɣ�Ĭ������ 10��none 65535
	//cout << "ͷ��㣺" << head->data << endl; // 0
	//cout << "β��㣺" << end->data << endl; // 9
	//cout << "β������һ����" << end->next->data << endl; // 0
}
//�Ƿ�Ϊ��
bool cyNode::is_Empty()
{
	if (rear == head && head->data == none)
	{
		return true;
	}
	return false;
}
//�Ƿ����
bool cyNode::is_Fullfill()
{
	if (rear->next == head && head->data != none)
	{
		return true;
	}
	return false;
}
//���
void cyNode::En_Queue()
{
	if (is_Fullfill())
	{
		cout << "��ǰ�����������޷����" << endl;
		return;
	}
	cout << "��������Ҫ��ӵ����ݣ�" << endl;
	int n;
	cin >> n;
	rear->data = n;
	rear = rear->next;
	cout << "��ӳɹ�" << endl;
}
//����
void cyNode::De_Queue()
{
	if (is_Empty())
	{
		cout << "��ǰ����Ϊ�գ��޷�����" << endl;
		return;
	}
	int temp = head->data;
	head->data = none;
	head = head->next;

	cout << "Ԫ�أ�" << temp << "���ӳɹ�" << endl;
}

int main()
{
	cyNode cn;
	cout << "��Ӳ��ԣ�" << endl;
	cout << "1��";  cn.En_Queue();
	cout << "2��";  cn.En_Queue();
	cout << "3��";  cn.En_Queue();
	cout << "4��";  cn.En_Queue();
	cout << "5��";  cn.En_Queue();
	cout << "6��";  cn.En_Queue();
	cout << "7��";  cn.En_Queue();
	cout << "8��";  cn.En_Queue();
	cout << "9��";  cn.En_Queue();
	cout << "���Ӧ���벻�ˣ�";  cn.En_Queue();

	cout << "���Ӳ��ԣ�" << endl;
	cn.De_Queue();
	cout << "���Ӳ��ԣ�" << endl;
	cn.De_Queue();
	cout << "���Ӳ��ԣ�" << endl;
	cn.De_Queue();
	cout << "���Ӳ��ԣ�" << endl;
	cn.De_Queue();

	cout << "11��";  cn.En_Queue();
	cout << "12��";  cn.En_Queue();
	cout << "13��";  cn.En_Queue();
	cout << "14��";  cn.En_Queue();
	cout << "���Ӧ��Ҳ�벻�ˣ�";  cn.En_Queue();

	system("pause");
	return 0;
}
