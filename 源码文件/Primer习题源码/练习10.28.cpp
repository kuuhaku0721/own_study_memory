/*
* 练习使用三种插入器
*/
#include <iostream>
#include <string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	list<int> li1, li2, li3;

	unique_copy(v.begin(), v.end(), inserter(li1, li1.begin()));
	for (auto it : li1)
	{
		cout << it << " ";
	}
	cout << endl;

	unique_copy(v.begin(), v.end(), back_inserter(li2));
	for (auto it : li2)
	{
		cout << it << " ";
	}
	cout << endl;

	unique_copy(v.begin(), v.end(), front_inserter(li3));
	for (auto it : li3)
	{
		cout << it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

