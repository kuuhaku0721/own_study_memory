#include <iostream>
#include <string>
#include<deque>
using namespace std;

class Solution
{
public:
	void cinToDeque()
	{
		deque<string> d;
		string word;
		while (cin >> word)
		{
			d.push_front(word);
		}
		//循环遍历输出
		for (auto it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

