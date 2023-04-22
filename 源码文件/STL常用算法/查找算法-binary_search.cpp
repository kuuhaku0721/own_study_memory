#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
* 二分查找法
* binary_search(begin, end, value);
* 查找指定元素，查到返回true 没有返回false
* 在无序的容器内不可用
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(2);  //再插入一个让其成为无序的
	//二分查找
	bool ret = binary_search(v.begin(), v.end(), 9);  //无序序列结果正确与否不确定
	if (ret)
	{
		cout << "找到了,但是二分查找无法打印输出" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//查找自定义数据类型  要重载==

int main()
{

	test01();



	system("pause");
	return 0;
}

