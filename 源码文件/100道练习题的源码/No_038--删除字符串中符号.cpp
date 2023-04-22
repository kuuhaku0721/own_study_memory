/*
* 假定输入的字符串中只包含字母和*号。请编写函数 fun()，它的功能是：将字符
* 串中的前导*号全部删除，中间和后面的*号不删除。例如，
* 若字符串中的内容为****A*BC*DEF*G*******，删除后，字符串中的内容
* 则应当是A*BC*DEF*G*******。
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
	cout << s << endl;
}
int main()
{
	func();

	system("pause");
	return 0;
}

