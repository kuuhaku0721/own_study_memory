/*
* 练习使用unique_copy函数
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,5,6 };
	list<int> li;

	//可以去掉重复
	unique_copy(v.begin(), v.end(), back_inserter(li)); //list并没有数据在里面，所以要用back_inserter

	for (auto it : li)
	{
		cout << it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

