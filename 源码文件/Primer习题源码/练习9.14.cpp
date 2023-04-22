/*
* 将list中的char* 指针元素赋值给一个vector的string
*/
#include <iostream>
#include <string>
#include<list>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<string>& listCharToVector(list<char*>& L)
	{
		vector<string> v;
		v.assign(L.begin(), L.end());

		return v;
	}
};

int main()
{
	

	system("pause");
	return 0;
}

