#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
* adjacent_find(begin, end);
* 查找相邻重复元素，返回相邻元素第一个位置的迭代器
*/
void test01()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	//查找相邻的重复元素
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "找到了并且=" << *pos << endl;
	}
	else
	{
		cout << "未找到相邻重复元素" << endl;
	}
}
int main()
{

	test01();



	system("pause");
	return 0;
}

