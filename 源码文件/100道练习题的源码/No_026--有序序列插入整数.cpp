/*
* 有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列仍然是升序。
*/
/*
* 参考答案用的数组
* 正统应该用链表
* 但是！ 我可以用set(multiset)容器
*/
#include <iostream>
#include <string>
#include<set>
using namespace std;
void insertNum()
{
	cout << "请输入数列个数n：";
	int n;
	cin >> n;
	cout << "请输入n个数字：" << endl;
	multiset<int> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}
	cout << "请输入想要插入的数字：";
	int i;
	cin >> i;
	s.insert(i);
	cout << "插入之后序列为：" << endl;
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	insertNum();

	system("pause");
	return 0;
}

