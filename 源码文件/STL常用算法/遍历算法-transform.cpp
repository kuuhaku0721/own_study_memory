#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* transform 将一个容器搬运到另一个容器当中
* 四个参数：源容器开始迭代器，源容器结束迭代器，目标容器开始迭代器，函数或函数对象
*/
class Transform
{
public:
	int operator()(int v)
	{
		return v+1000;  //如果要做逻辑运算就在这里修改,比如+1000
	}
};
class print01
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> target; //目标容器
	target.resize(v.size()); //目标容器就算不传数也一定要开辟空间
	transform(v.begin(), v.end(), target.begin(), Transform());  //搬运
	for_each(target.begin(), target.end(), print01());  //打印
}
int main()
{

	test01();



	system("pause");
	return 0;
}
