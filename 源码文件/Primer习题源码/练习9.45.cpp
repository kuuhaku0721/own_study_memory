/*
* 编写一个函数，接受一个表示名字的string和两个分别表示前缀和后缀的字符串
* 使用迭代器insert和append将前缀和后缀添加到给定的名字中生成新的string并返回
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

void name_string(string& name, string prefix, string suffix)
{
	name.insert(name.begin(), 1, ' '); //先加一个分隔符，把名字和前后缀分开
	name.insert(name.begin(), prefix.begin(), prefix.end()); //插入前缀
	name.append(" "); //加空格让名字和后缀分开
	name.append(suffix.begin(), suffix.end()); //将后缀以append形式插入最后
}

int main()
{
	string s = "James Bond";
	string prefix, suffix;
	prefix = "Mr";
	suffix = "II";
	name_string(s, prefix, suffix);
	cout << s << endl;

	system("pause");
	return 0;
}

