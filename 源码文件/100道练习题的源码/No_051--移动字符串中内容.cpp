/*
* 请编写函数 fun，该函数的功能是移动字符串中内容，移动的规则如下：把第 1 到
* 第 m 个字符，平移到字符串的最后，把第 m＋1 到最后的字符移到字符串的前部
*/
#include <iostream>
#include <string>
using namespace std;
void moveStr()
{
	//默认输入合法
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	cout << "请输入想要移动的位置：" << endl;
	int p;
	cin >> p;
	string str;
	for (int i = s.size()-p + 1; i < s.size(); i++)
	{
		str += s[i];
	}
	for (int i = 0; i < p; i++)
	{
		str += s[i];
	}
	cout << str << endl;
}
int main()
{
	moveStr();

	system("pause");
	return 0;
}

