/*
* 编写函数接受三个string参数s,oldVal,newVal 使用迭代器及insert和erase函数实现replace功能
*/
#include <iostream>
#include <string>
using namespace std;

void replace_string(string& s,const string oldVal, const string newVal)
{
	auto len = oldVal.size();
	if (!len) //如果子串为空
	{
		return;
	}
	auto iter = s.begin();
	while (iter <= s.end() - 1) //最后少于oldVal长的部分无需检查
	{
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		while (iter2 != oldVal.end() && *iter1 == *iter2)
		{ //循环oldVal，并且s中iter开始的子串每个字符都与oldVal相同
			iter1++;
			iter2++;
		}
		if (iter2 == oldVal.end()) //比较到头说明s的子串与oldVal完全匹配
		{
			iter = s.erase(iter, iter1); //删除s中与oldVal相等的部分
			if (newVal.size())
			{ //替换的子串不为空
				iter2 = newVal.end() - 1;
				while (iter2 >= newVal.begin())
				{
					iter = s.insert(iter, *iter2);
					iter2--;
				}
			}
			iter += newVal.size(); //迭代器移动到新插入的内容之后
		}
		else
		{
			iter++;
		}
	}
}

int main()
{
	string s = "tho thru tho!";
	replace_string(s, "thru", "through");
	cout << s << endl;

	replace_string(s, "tho", "though");
	cout << s << endl;

	replace_string(s, "through", "");
	cout << s << endl;

	system("pause");
	return 0;
}

