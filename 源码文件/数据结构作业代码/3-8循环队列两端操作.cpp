/*
* ���������ѭ�����е����˶����Խ��в����ɾ������
* 1��д��ѭ�����е����Ͷ���
* 2��д�����Ӷ�βɾ�����͡��Ӷ�ͷ���롱���㷨
*/
//ps:���㲻����deque�𣿣���ֱ��һ��#include<deque> 2333333
#include <iostream>
#include <string>
using namespace std;

struct Queue
{
	const static int MAXSIZE = 5;
	int data[MAXSIZE]; //���д洢����
	int front, rear; //��ͷ����β
	int tag = 0; //0��ʾ�գ�1��ʾ��
};
class deque
{
public:
	deque();//���г�ʼ��
	void push_front(); 
	void push_back();
	void pop_front();
	void pop_back();
private:
	Queue* Q;
};

//��ʼ��
deque::deque()
{
	Q = new Queue;
	Q->front = 0; //��ʼ����ͷΪ�����һ��λ��
	Q->rear = 1; //��β������ڶ���λ��  
	Q->tag = 0; //��־λ��0

	cout << "��ʼ�����" << endl;
}

//���
void deque::push_front()
{
	cout << "��������Ҫ��ӵ�Ԫ�أ�" << endl;
	int n;
	cin >> n;

	//�ж϶�����
	if (Q->tag == 1)
	{
		cout << "�����������޷����" << endl;
		return;
	}
	//��Ӳ���
	Q->data[Q->front] = n;
	Q->front = (Q->front - 1 + Q->MAXSIZE) % Q->MAXSIZE;
	if ((Q->front - Q->rear) == -1)
	{
		Q->tag = 1;
	}
	cout << "��ӳɹ�" << endl;
}
void deque::push_back()
{
	cout << "��������Ҫ��ӵ�Ԫ�أ�" << endl;
	int n;
	cin >> n;

	//�ж϶�����
	if (Q->tag == 1)
	{
		cout << "�����������޷����" << endl;
		return;
	}
	//��Ӳ�����ע����ѭ������
	Q->data[Q->rear] = n;
	Q->rear = (Q->rear + 1) % Q->MAXSIZE;
	//��ǰ����Ӳ������ж����ڵ�rear��front��λ�ã��Դ˾���tag
	if ((Q->front - Q->rear) == 1)
	{
		Q->tag = 1;
	}
	cout << "��ӳɹ�" << endl;
}


//����
void deque::pop_front()
{
	//�ж϶��Ƿ�Ϊ��
	if (Q->tag == 0)
	{
		cout << "��ǰ����Ϊ�գ��޷�����" << endl;
		return;
	}
	//���Ӳ������ѳ��ӵ�Ԫ�ش�ӡ��ȥ
	int top = Q->data[Q->front];
	Q->front = (Q->front + 1) % Q->MAXSIZE; //��ͷ����
	//����tag
	if ((Q->front - Q->rear) == 1)
	{
		Q->tag = 0;
	}
	cout << top << " ���ӳɹ�" << endl;
}
void deque::pop_back()
{
	//�ж϶��Ƿ�Ϊ��
	if (Q->tag == 0)
	{
		cout << "��ǰ����Ϊ�գ��޷�����" << endl;
		return;
	}
	//����
	int back = Q->data[Q->rear];
	Q->rear = (Q->rear - 1 + Q->MAXSIZE) % Q->MAXSIZE;
	//����tag
	if ((Q->front- Q->rear) == -1)
	{
		Q->tag = 0;
	}
	cout << back << " ���ӳɹ�" << endl;
}


void init()
{
	deque dq;

	while (1)
	{
		cout << "1----�Ӷ�ͷ��" << endl;
		cout << "2----�Ӷ�β��" << endl;
		cout << "3----�Ӷ�ͷ��" << endl;
		cout << "4----�Ӷ�β��" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			dq.push_front();
			system("pause");
			system("cls");
			break;
		case 2:
			dq.push_back();
			system("pause");
			system("cls");
			break;
		case 3:
			dq.pop_front();
			system("pause");
			system("cls");
			break;
		case 4:
			dq.pop_back();
			system("pause");
			system("cls");
			break;
		default:
			cout << "�˳�" << endl;
			return;
		}
	}
}
int main()
{
	init();

	system("pause");
	return 0;
}

