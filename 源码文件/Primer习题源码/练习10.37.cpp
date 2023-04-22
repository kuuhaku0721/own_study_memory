/*
* 给定一个包含10个元素的vector，将第3到7的位置之间的元素按逆序拷贝到一个list中
* 
* 练习反向迭代器使用
*/
#include <iostream>
#include <string>
#include<list>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	//用流迭代器和copy输出int序列
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	list<int> li;
	//将v[2]，也就是第三个位置转换为反向迭代器
	vector<int>::reverse_iterator re(v.begin() + 2);
	//将v[7]，也就是第八个位置转换为反向迭代器
	vector<int>::reverse_iterator rb(v.begin() + 7);
	//用反向迭代器将元素拷贝到list中
	copy(rb, re, back_inserter(li));
	copy(li.begin(), li.end(), out_iter);
	cout << endl;


	system("pause");
	return 0;
}

