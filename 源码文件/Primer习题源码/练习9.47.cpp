﻿/*
* 编写程序，首先查找string， ”ab2c3d7R4E6“ 中的每个数字字符，然后查找其中的每个字母字符
* 编写两个程序版本，第一个使用find_dirst_of 第二个使用 find_first_not_of
*/
#include <iostream>
#include <string>
using namespace std;

void find_char(string& s, const string& chars)
{
	cout << "在" << s << "中查找" << chars << "中字符" << endl;
	string::size_type pos = 0;
	while ((pos = s.find_first_of(chars, pos)) != string::npos) //找到字符
	{
		cout << "pos:" << pos << "，char：" << s[pos] << endl;
		pos++; //移动到下一字符
	}
}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "查找所有数字：" << endl;
	find_char(s, "0123456789");
	cout << endl << "查找所有字母：" << endl;
	find_char(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	system("pause");
	return 0;
}

