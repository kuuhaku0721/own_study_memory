/*
* 将两个栈存放于同一个数组空间中，栈底分别位于数组的两端。当第0号栈顶指针top[0] = -1 时栈为空，当第1号栈的栈顶指针top[1] = m 时，栈为空
* 两栈均从两端向中间增长
* 试编写双栈初始化，判断栈空，栈满，进栈和出栈等算法的函数
*/
#include <iostream>
#include <string>
using namespace std;
//双栈的定义
struct DblStack
{
	int top[2], bot[2]; //栈顶和栈底指针
	int nums[10]; //栈数组
	int max = 10; //数组最大数量
};

class bidirectionalStack
{
public:
	bidirectionalStack(); //双栈的初始化
	bool is_Empty(int index); //判断是否为空
	bool is_Fullfill(); //判断是否为满
	void Push_DbStack(); //入栈
	void Pop_DbStack(); //出栈
private:
	DblStack* sck;
};
//双栈初始化
bidirectionalStack::bidirectionalStack()
{
	sck = new DblStack;
	//左闭右开，即栈顶指向当前元素，栈底指向最后一个元素的下一个元素
	sck->top[0] = -1;
	sck->bot[0] = sck->top[0];  //左栈的栈顶和栈底

	sck->top[1] = sck->max;
	sck->bot[1] = sck->top[1]; //右栈的栈顶和栈底
}
//判断栈为空或满
bool bidirectionalStack::is_Empty(int index)
{
	if (index == 0)
	{
		if (sck->top[index] == -1)
		{
			return true;
		}
		else return false;
	}
	else
	{
		if (sck->top[index] == sck->max)
		{
			return true;
		}
		else return false;
	}
}
bool bidirectionalStack::is_Fullfill()
{
	if (sck->top[0] == sck->top[1] - 1)
	{
		return true;
	}
	return false;
}
//入栈
void bidirectionalStack::Push_DbStack()
{
	cout << "请输入想要入栈的元素：" << endl;
	int n;
	cin >> n;
	cout << "请输入想要入栈的序号：" << endl;
	int index;
	cin >> index;
	if (index < 0 || index > 1)
	{
		cout << "索引不合法" << endl;
		return;
	}
	//入栈
	if (is_Fullfill())
	{
		cout << "当前栈已满，无法入栈" << endl;
		return;
	}
	if (index == 0)
	{
		sck->top[0]++;
		sck->nums[sck->top[0]] = n;
		cout << "入栈成功" << endl;
	}
	if (index == 1)
	{
		sck->top[1]--;
		sck->nums[sck->top[1]] = n;
		cout << "入栈成功" << endl;
	}
}
//出栈
void bidirectionalStack::Pop_DbStack()
{
	cout << "请输入想要出栈的栈序号：" << endl;
	int index;
	cin >> index;
	if (index < 0 || index > 1)
	{
		throw invalid_argument("索引不合法"); //抛异常
		//这个不会用........
	}
	if (index == 0)
	{
		if (is_Empty(index))
		{
			cout << "当前栈为空，无法出栈" << endl;
			return;
		}
		int t = sck->nums[sck->top[index]];
		sck->top[index]--;
		cout << "元素：" << t << "出栈成功" << endl;
	}
	if (index == 1)
	{
		if (is_Empty(index))
		{
			cout << "当前栈为空，无法出栈" << endl;
			return;
		}
		int t = sck->nums[sck->top[index]];
		sck->top[index]++;
		cout << "元素：" << t << "出栈成功" << endl;
	}
}

int main()
{
	bidirectionalStack bs;
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();
	cout << "--------到这里应该栈满-----" << endl;
	cout << "入栈测试：" << endl;
	bs.Push_DbStack();

	cout << "----------------" << endl;
	cout << "出栈测试：" << endl;
	bs.Pop_DbStack();
	cout << "出栈测试：" << endl;
	bs.Pop_DbStack();

	system("pause");
	return 0;
}

