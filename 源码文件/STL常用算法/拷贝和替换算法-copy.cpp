#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* copy(begin, end, dest_begin);
* 容器内指定范围的元素拷贝到另一容器中
* dest_begin 目标容器的起始迭代器
*/
void printVector(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size() - 4);
	copy(v1.begin()+2, v1.end()-2, v2.begin());

	for_each(v2.begin(), v2.end(), printVector);
	cout << endl;

}
int main()
{

	test01();



	system("pause");
	return 0;
}
