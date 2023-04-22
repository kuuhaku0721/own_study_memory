/*
* 请编写函数 fun，该函数的功能是：判断字符串是否为回文?若是则函数返回 1，主
* 函数中输出 yes，否则返回 0，主函数中输出 no。回文是指顺读和倒读都是一样的
* 字符串
*/
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
void fun()
{
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	string str = s;
	reverse(str.begin(), str.end());
	if (s == str)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
}
int main()
{
	fun();

	system("pause");
	return 0;
}

