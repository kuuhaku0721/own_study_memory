/*
* 编写一个函数，该函数可以统计一个长度为 2 的字符串在另一个字符串中出现的次数。
*/
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
void countStr()
{
	cout << "请输入长字符串：" << endl;
	string s;
	cin >> s;
	cout << "请输入要统计的长度为2字符串：" << endl;
	string str;
	cin >> str;
	int num = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == str[0] && s[i + 1] == str[1])
		{
			num++;
		}
	}
	cout << "次数：" << num << endl;
}
int main()
{
	countStr();

	system("pause");
	return 0;
}

