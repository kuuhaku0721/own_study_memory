/*
* 编写一个函数 fun，它的功能是：实现两个字符串的连接(不使用库函数 strcat)，
* 即把 p2 所指的字符串连接到 p1 所指的字符串后
*/
#include <iostream>
#include <string>
using namespace std;
void unionStr()
{
	cout << "请输入第一个字符串：" << endl;
	string s1;
	cin >> s1;
	cout << "请输入第二个字符串：" << endl;
	string s2;
	cin >> s2;
	s1 = s1 + s2;
	cout << s1 << endl;
}
int main()
{
	unionStr();

	system("pause");
	return 0;
}

