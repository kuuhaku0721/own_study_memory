/*
* 编写你自己版本的验证电话号码的程序
*/
#include <iostream>
#include <string>
#include<regex>
using namespace std;

//区号部分不包含分隔符
//剩余部分中的分隔符必须相同
//或是区号部分有正确的括号，且下一个分隔符是空白或无分隔符

bool valid(const smatch& m)
{
	//如果区号前是一个左括号
	if (m[1].matched)
	{
		//则区号后必须是一个右括号，且立即跟随剩余数字或一个空格
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else
	{
		//否则，区号后不能有右括号，其他两部分间的分隔符必须相同
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

int main()
{
	//整个政策表达式有7个子表达式
	//(ddd) 分隔符 ddd 分隔符 dddd
	//子表达式1、3、4和6是可选的
	//子表达式2、5和7匹配号码
	string phone = "(\\()?(\\d{3})(\\)?([-.])?(\ \d{3})([-.]?)(\\d{4})";
	regex r(phone); //查找模式用的regex
	smatch m; //保存匹配结果的对象
	string s; //要搜索的字符串

	//从输入文件读取每条记录
	while (getline(cin, s))
	{
		//对每个匹配的电话号码
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; it++)
		{
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
		}
	}

	system("pause");
	return 0;
}

