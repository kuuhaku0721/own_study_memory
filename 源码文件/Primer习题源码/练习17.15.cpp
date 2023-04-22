/*
* 编写程序，使用模式查找违反“i在e之前，除非在c之后”规则的单词
* 你的程序应该提示用户输入一个单词，然后指出此单词是否符合要求，用一些违反和未违反规则的单词测试你的程序
*/
#include <iostream>
#include <string>
#include<regex>
using namespace std;

int main()
{
	//查找不在字符c之后的字符串ei
	string pattern("[^c]ei");
	//我们需要包含pattern的整个单词
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern); //构造一个用于查找模式的regex
	smatch results; //定义一个对象保存搜索结果
	//定义一个string保存与模式匹配和不匹配的文本
	string test_str;
	while (1)
	{
		cout << "Enter a word. or q to quit:";
		cin >> test_str;
		if (test_str == "q") break;

		//用r在test_str中查找与pattern匹配的子串
		if (regex_search(test_str, results, r)) //如果有匹配的子串
			cout << results.str() << endl;  //打印匹配的单词
	}

	system("pause");
	return 0;
}

