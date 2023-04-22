/*
* 编写函数，接受一对指向vector<int>的迭代器和int值，查找给定的值，返回布尔来判断是否找到
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Solution
{
public:
	bool searchInVectorInt(vector<int>& v, int val)
	{
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			if (*it == val)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

