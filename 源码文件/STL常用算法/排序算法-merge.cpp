#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* merge(begin1, end1, begin2, end2, dest_begin);
* 容器元素合并，并存储到另一容器中
* dest_begin 目标容器的开始迭代器
* 注意两个容器必须是有序的才能合并，合并后仍然是有序的
*/
void printVector(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
	}
	//目标容器
	vector<int> v3;
	v3.resize(v1.size() + v2.size());  //目标容器要提前分配空间
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printVector(v3);
	

}

int main()
{

	test01();



	system("pause");
	return 0;
}

