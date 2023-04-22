/*
* ����������Q[m]���ѭ�������е�Ԫ�أ�ͬʱ����һ����־tag����tag=0��tag=1�����𵱶�ͷָ��front�Ͷ�βָ��rear���ʱ������Ϊ�ջ���Ϊ��
* �Ա�д��Ӧ�Ĳ���enqueue��ɾ��dequeue�㷨
*/
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
class queue
{
public:
	queue();//���г�ʼ��
	void En_Queue(); //���
	void De_Queue(); //����

private:
	Queue* Q;
};
//��ʼ��
queue::queue()
{
	Q = new Queue;
	Q->front = Q->rear = 0; //����ҿ��ṹ����ͷ���ǵ�ǰԪ�أ���βָ��ǰԪ����һ��λ��
	//                      ��˼�����Ժ���ӵ�ʱ���ȼ���Ԫ�أ�Ȼ���ö�β���ƣ����ӵ�ʱ��������Ԫ�أ�Ȼ���ͷ����
	Q->tag = 0; //��־λ��0

	cout << "��ʼ�����" << endl;
}
//���
void queue::En_Queue()
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
	if (Q->rear == Q->front)
	{
		Q->tag = 1;
	}
	cout << "��ӳɹ�" << endl;
}
//����
void queue::De_Queue()
{
	//�ж϶��Ƿ�Ϊ��
	if (Q->tag == 0 && Q->front == Q->rear)
	{
		cout << "��ǰ����Ϊ�գ��޷�����" << endl;
		return;
	}
	//���Ӳ������ѳ��ӵ�Ԫ�ش�ӡ��ȥ
	int top = Q->data[Q->front];
	Q->front = (Q->front + 1) % Q->MAXSIZE; //��ͷ����
	//����tag
	if (Q->front == Q->rear)
	{
		Q->tag = 0;
	}
	cout << top << " ���ӳɹ�" << endl;
}

int main()
{
	
	queue q;

	//��Ӳ���
	cout << "��Ӳ��ԣ�" << endl;
	q.En_Queue();
	q.En_Queue();
	q.En_Queue();
	q.En_Queue();
	q.En_Queue();
	q.En_Queue();

	cout << "���Ӳ��ԣ�" << endl;
	q.De_Queue();
	q.De_Queue();
	q.De_Queue();
	q.De_Queue();
	q.De_Queue();
	q.De_Queue();

	system("pause");
	return 0;
}

