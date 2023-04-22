#include <iostream>
#include <string>
#include<deque>
#include<list>
using namespace std;

class Solution
{
public:
	void cinToDeque(list<int>& L)
	{
		deque<int> d1; //存放奇数
		deque<int> d2; //存放偶数
		for (auto it = L.begin(); it != L.end(); it++)
		{
			if (*it % 2 == 0)
			{
				d2.push_front(*it);
			}
			else
			{
				d1.push_front(*it);
			}
		}
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

