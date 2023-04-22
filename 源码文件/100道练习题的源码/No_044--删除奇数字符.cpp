/*
* 将 s 所指字符串中除了下标为奇数、同时 ascii 值也为奇数的字符之外，其余的所
* 有字符都删除，串中剩余字符所形成的一个新串放在 t 所指的一个数组中
*/
#include <iostream>
#include <string>
using namespace std;
void deleteStr()
{
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (i % 2 != 0 && s[i] % 2 != 0)
		{
			str += s[i];
		}
	}
	cout << "结果：" << str << endl;
}
int main()
{
	deleteStr();

	system("pause");
	return 0;
}

