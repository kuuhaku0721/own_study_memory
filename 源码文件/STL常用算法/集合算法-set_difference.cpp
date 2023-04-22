#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* set_difference(begin1, end1, begin2, end2, dest_begin);
* 求两个容器的差集并传送到另一个容器内
* dest_begin 目标容器迭代器
* 有序
*/
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v3;
	vector<int> v4;
	//目标容器提前开辟空间
	v3.resize(max(v1.size(),v2.size()));
	v4.resize(max(v1.size(),v2.size()));
	//获取并集  会返回一个迭代器
	vector<int>::iterator pos;
	pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, myPrint);  //注意这里第二个参数，要用差集结尾而不是集合结尾
	cout << endl;
	//差集有两种情况
	pos = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v4.begin());
	for_each(v4.begin(), pos, myPrint);  //注意这里第二个参数，要用差集结尾而不是集合结尾
	cout << endl;
}

int main()
{

	test01();



	system("pause");
	return 0;
}
