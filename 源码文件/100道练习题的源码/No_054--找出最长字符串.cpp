/*
* 编写一个函数，从传入的 num 个字符串中找出一个最长的一个字符串，并通过形参
* 指针 max 传回该串地址(用****作为结束输入的标志)
*/
//问题，题目给的意思着实不能理解无法实现，鬼知道它说的啥，如果要返回最长串的地址，就需要提前保存所有串，或者至少保存两个串
//但是题目又说不确定总数，那就需要无限循环输入，但是又不能无限循环输入无限申请空间，就需要数组来保存，但是数组又需要确定长度
//如果用容器可以不确定长度，但是容器的迭代器指针是没法输出的
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void longest()
{
	cout << "请输入字符串，以*结束：" << endl;
	vector<string> v;
	while (true)
	{
		string s;
		cin >> s;
		if (s == "*")
		{
			break;
		}
		v.push_back(s);
	}
	//迭代器就是指针,但是迭代器没法直接赋值给int*的指针
	vector<string>::iterator back = v.begin();
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*back).size() <= (*it).size())
		{
			back = it;
		}
	}
	cout << "最长的是：" << *back << endl;
}
int main()
{
	longest();

	system("pause");
	return 0;
}

