/*
* 编写一个Foo类，其中sorted函数中有打印语句
* 
* 理解左值引用和右值引用版本的成员函数
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

class Foo
{
public:
	Foo sorted()&&; //用于可改变的右值
	Foo sorted() const&; //可用于任何类型的Foo
	//Foo其他成员的定义
private:
	vector<int> data;
};

//本对象为右值，因此可以原地址排序
Foo Foo::sorted()&&
{
	cout << "右值引用版本" << endl;
	sort(data.begin(), data.end());
	return *this;
}
//本对象是const或是一个左值，哪种情况我们都不能对其进行原址排序
Foo Foo::sorted() const&
{
	cout << "左值引用版本" << endl;
	Foo ret(*this); //拷贝一个副本
	return ret.sorted(); //排序副本而不是本体
}

int main()
{
	Foo f;
	f.sorted();

	system("pause");
	return 0;
}

