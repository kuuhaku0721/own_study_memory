/*
* 编写程序，将九位数字邮政编码的格式转换为ddddd-dddd
* 
* 练习正则表达式和模式匹配
*/
#include <iostream>
#include <string>
#include<regex>
using namespace std;

int main()
{
	string zip = "(\\d{5})((-?)(\\d{4}))?";
	regex r(zip); //寻找模式所用的regex对象
	string s;
	string fmt = "$1-$2"; //改变格式为ddddd-dddd
	//从输入文件中读取每条记录
	while (getline(cin, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; it++)
		{
			if ((*it)[2].matched && (*it)[2].str()[0] != '-')
				cout << (*it).format(fmt) << endl;
			else
				cout << (*it).str() << endl;
		}
	}

	system("pause");
	return 0;
}

