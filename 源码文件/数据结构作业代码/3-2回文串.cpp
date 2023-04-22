/*
* ����ջ���ж�һ���ַ����Ƿ��ǻ��Ĵ�
*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;
class Solution
{
public:
	bool itCanReverse(string str)
	{
		stack<char> s;
		int n = str.size() / 2;
		for (int i = 0; i < n; i++)
		{
			s.push(str[i]);
		}
		int i = 0;
		if (str.size() % 2 == 0)
		{
			i = n;
		}
		else {
			i = n + 1;
		}
		while (!s.empty() && i < str.size())
		{
			if (str[i] != s.top())
			{
				return false;
			}
			i++;
			s.pop();
		}
		return true;
	}
};

int main()
{
	string s = "ABbaabBA";
	if (Solution().itCanReverse(s))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	system("pause");
	return 0;
}

