/*
* ��ջ�洢������������������-1����ջ�������-1�����ջ������ջ
*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;
class Solution
{
public:
	void putInUnlessMinusOne()
	{
		stack<int> s;  //��Ҫ��ʱ���Լ��ִ�һ��ջ
		while (1)
		{
			int n;
			cin >> n;
			if (n == -1)
			{
				if (s.empty())
				{
					cout << "stack is empty" << endl;
					break;
				}
				cout << s.top() << endl;
				s.pop();
			}
			else if(n > -1)
			{
				s.push(n); //Ȼ��������п�����Ҫ�ж��Ƿ�ջ��
			}
			else
			{
				break;
			}
		}
	}
};

int main()
{
	Solution().putInUnlessMinusOne();

	system("pause");
	return 0;
}

