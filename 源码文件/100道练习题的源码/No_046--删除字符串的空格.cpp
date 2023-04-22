/*
* 请编写一个函数，用来删除字符串中的所有空格
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void backspace()
{
	//cout << "请输入字符串：" << endl;
	//不能输入字符串，输入的话会按照空格分割，空格之后全都算作第二个字符串，输入的字符串无法输入空格
	string s = "h  e  l lo      worl    d";
	//cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
	cout << s << endl;
}
int main()
{
	backspace();

	system("pause");
	return 0;
}