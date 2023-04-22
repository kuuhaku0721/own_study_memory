/*
* 编写行为类似标准库find算法的模板。函数需要两个模板类型参数，一个表示函数的迭代器参数
* 零一个表示值的类型。使用你的函数在一个vector<int>和一个list<string>中查找给定值
*/
#include <iostream>
#include <string>
#include<vector>
#include<list>
using namespace std;

template <typename I, typename T>
I my_find(I b, I e, const T& v) //不要用find当作名字，因为标准库有find，编译器会不知道调用哪一个
{
	while (b != e && *b != v)
	{
		b++;
	}
	return b;
}

int main()
{
	vector<int> vi = { 0,2,4,6,8,10 };
	list<string> ls = { "Hello", "World", "!" };

	auto iter = my_find(vi.begin(), vi.end(), 6);
	if (iter == vi.end())
	{
		cout << "can not find 6" << endl;
	}
	else
	{
		cout << "find 6 at position " << iter - vi.begin() << endl;
	}

	auto iter1 = my_find(ls.begin(), ls.end(), "mon");
	if (iter1 == ls.end())
	{
		cout << "can not find mom" << endl;
	}
	else
	{
		cout << "found mom" << endl;
	}

	system("pause");
	return 0;
}

