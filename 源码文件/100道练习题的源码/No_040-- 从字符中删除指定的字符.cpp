/*
* 编写函数 fun,该函数的功能是：从字符中删除指定的字符，同一字母的大、小写
* 按不同字符处理。
*/
#include <iostream>
#include <string>
using namespace std;
void fun()
{
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	cout << "请输入想要删除的字符：";
	char c;
	cin >> c;
	while (1)
	{
		int res = s.find(c);
		if (res != -1)
		{
			s.erase(res, 1);
		}
		else
		{
			break;
		}
	}
	cout << "结果：" << s << endl;
}
int main()
{
	fun();

	system("pause");
	return 0;
}

