/*
* 假定输入的字符串中只包含字母和*号。请编写函数 fun，它的功能是：将字符串
* 中的前导*号全部移到字符串的尾部
*/
#include <iostream>
#include <string>
using namespace std;
void func()
{
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	s.erase(0, cnt);
	for (int i = 0; i < cnt; i++)
	{
		s += '*';
	}
	cout << "结果：" << s << endl;
}
int main()
{
	func();

	system("pause");
	return 0;
}

