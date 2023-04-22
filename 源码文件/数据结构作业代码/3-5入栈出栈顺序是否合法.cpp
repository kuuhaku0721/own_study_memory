/*
* ����һ����ջ��ջ˳���� ��ʹ��I����ջ��O����ջ�����жϸ�˳���Ƿ�Ϸ�
*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;

class Solution
{
public:
	bool pushAndPopIsLegal(string str)
	{
		stack<int> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'I')
			{
				s.push(1);
			}
			if (str[i] == 'O')
			{
				if (s.empty())
				{
					return false;
				}
				s.pop();
			}
		}
		return true;
	}
};

int main()
{
	string s = "IOO";
	if (Solution().pushAndPopIsLegal(s))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	system("pause");
	return 0;
}

