/*
* ��������һ����׺���ʽ��������ʽ��ֵ�����ʽ������һ�У���$������������֮���ÿո�ָ�����ֻ��+-*��/
*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;

class Solution
{
public:
	void lastOrderCalculator()
	{ //ջ��Ԫ����������ұ�
		string str;
		cout << "Put in the string��" << endl;
		getline(cin, str);
		stack<string> s;
		string t;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				t += str[i];
			}
			if (str[i] == ' ' && t != "")
			{
				s.push(t);
				t = "";
			}
			if (str[i] == '+')
			{
				string a = s.top();
				int num1 = atoi(a.c_str());
				s.pop();
				string b = s.top();
				int num2 = atoi(b.c_str());
				s.pop();
				num1 += num2;
				s.push(to_string(num1));
			}
			if (str[i] == '-')
			{
				string a = s.top();
				int num1 = atoi(a.c_str());
				s.pop();
				string b = s.top();
				int num2 = atoi(b.c_str());
				s.pop();
				num2 -= num1;
				s.push(to_string(num2));
			}
			if (str[i] == '*')
			{
				string a = s.top();
				int num1 = atoi(a.c_str());
				s.pop();
				string b = s.top();
				int num2 = atoi(b.c_str());
				s.pop();
				num1 *= num2;
				s.push(to_string(num1));
			}
			if (str[i] == '/')
			{
				string a = s.top();
				int num1 = atoi(a.c_str());
				s.pop();
				string b = s.top();
				int num2 = atoi(b.c_str());
				s.pop();
				num2 = num2 / num1;
				s.push(to_string(num2));
			}
			if (str[i] == '$')
			{
				break;
			}
		}
		//cout << "����stack�Ĵ�С��" << s.size() << endl;
		//���ս��
		cout << s.top() << endl;
	}
};

int main()
{
	Solution().lastOrderCalculator();

	system("pause");
	return 0;
}

