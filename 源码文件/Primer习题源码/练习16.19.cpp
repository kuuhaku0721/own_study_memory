/*
* 编写函数，接受一个容器的引用，打印容器中的元素。使用容器的size_type和size成员来控制打印元素的循环
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

template <typename C>
void print(const C& c)
{
	for (typename C::size_type i = 0; i < c.size(); i++)
	{
		cout << c.at(i) << " ";  //用了at，默认了传进来的容器支持at函数，那么就不再适用于list和forward_list
	}
	cout << endl;

	//可以有begin和end返回的迭代器控制循环
	for (auto i = c.begin(); i != c.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int main()
{
	string s = "Hello!";
	print(s);

	vector<int> vi = { 0,2,4,6,8 };
	print(vi);

	system("pause");
	return 0;
}

