/*
* 比较一个list和一个vector元素是否相等
*/
#include <iostream>
#include <string>
#include<list>
#include<vector>
using namespace std;

class Solution
{
public:
	bool compareListAndVector(list<int>& L, vector<int>& v)
	{
		if (L.size() != v.size())
		{ //如果两个容器大小不一样肯定不会相等
			return false;
		}
		auto Lfirst = L.begin(); //list的首元素 auto
		auto Lback = L.end(); //list的末尾
		auto Vfirst = v.begin(); //vector的首元素
		for (; Lfirst != Lback; Lfirst++, Lback++)
		{
			if (*Lfirst != *Vfirst)
			{
				return false; //容器内某元素不相等
			}
		}
		return true; //比较完毕，全都相等
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

