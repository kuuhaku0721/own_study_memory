/*
* 编写函数，传入forward_list<list>和两个string
* 函数的功能是在list内寻找第一个string，并将第二个string插入到第一个之后
* 如果第一个string在list内不存在，那么就将第二个string插入到list末尾
*/
#include <iostream>
#include <string>
#include<forward_list>
using namespace std;

void test_and_insert(forward_list<string>& sflist, string& s1, string& s2)
{
	auto prev = sflist.before_begin(); //前驱元素
	auto curr = sflist.begin(); //当前元素
	bool inserted = false;

	while (curr != sflist.end())
	{
		if (*curr == s1) //如果相等
		{
			curr = sflist.insert_after(curr, s2); //将s2插入到s1后面，并且返回插入后的迭代器
			inserted = true;
		}
		prev = curr; //更改前驱迭代器
		curr++; //当前迭代器往后移动一位
	}
	if (!inserted) //没有找到，插入到list末尾
	{
		sflist.insert_after(prev, s2);
	}
}

int main()
{
	forward_list<string> sflist = { "hello", "!", "world", "!" };
	string s1 = "hello";
	string s2 = "你好";
	test_and_insert(sflist, s1, s2);  //注意如果在括号里面直接填写参数是const值，在函数列表里要加const

	for (auto curr = sflist.cbegin(); curr != sflist.end(); curr++)
	{
		cout << *curr << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

