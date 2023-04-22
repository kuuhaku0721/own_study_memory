#include <iostream>
#include <string>
#include <regex>
using namespace std;

/*
* 关于正则表达式的描述例子
* 例子：如果给定字符串S="Hello"，现在要匹配用户输入的字符串T是否包含S字符串"Hello"，
* 例如"78495Hello8984"包含了"Hello"，而"8495He110"并不包含"Hello"。
*/
/*
* 使用regex 对象名(格式字符串); 来生成正则表达式对象：
*	regex r("[[:print:]]*"+S+"[[:print:]]*");  //生成正则表达式对象
*	//[:print:]表示任意字母、数字、英文标点、空格，*表示0个或多个这样的字符
* 
* 在构造函数中增加参数regex::icase时为大小写不敏感。
*	regex r("[[:print:]]*"+S+"[[:print:]]*", regex::icase);
*/
/*
对于[[::]]的用法，举数例如下：

[[:alpha:]] 任意字母

[[:alnum:]] 任意字母、数字

[[:digit:]] 任意数字

[[:graph:]] 任意字母、数字、英文标点

[[:print:]] 任意字母、数字、英文标点、空格

[[:blank:]] 空格或制表符

[[:space:]] 空格

[[:lower:]] 任意小写字母

[[:upper:]] 任意大写字母

[[:punct:]] 任意英文标点

对于*的用法（*或以下其他符号代表前面[[:xxx:]]的数目），举数例如下：

* 0 or more ≥0

+ 1 or more ≥1

? 0 or 1 {0,1}

{int} int    e.g. {5}表示5个

{int,} int or more    e.g. {5,}表示≥5个

{min,max} between min and max(闭区间)    e.g. {5,9} ≥5且≤9
*/
void test_regex()
{
	/*
	* 1、正则匹配
	将 正则表达式对象 与 字符串对象 匹配
	判定 字符串对象 是否符合 正则表达式对象
	获取用户输入的字符串，匹配成功则屏幕输出"success"，反之"fail"：
	使用 regex_match(字符串， 正则表达式)函数，这是一个布尔型函数，匹配成功返回true，反之false
	*/
	string S = "Hello";
	regex r("[[:print:]]*" + S + "[[:print:]]*");
	string input_str;
	cin >> input_str;
	if (regex_match(input_str, r)) {
		cout << "success" << endl;
	}
	else {
		cout << "fail" << endl;
	}


	/*
	* 2、正则查找
	判定 字符串对象 是否包含 正则表达式对象
	例如，52aHellob25虽然和[[:alpha:]]*Hello[[:alpha:]]*不匹配，但却包含了[[:alpha:]]*Hello[[:alpha:]]*
	*/
	string S1 = "Hello";
	regex r1("[[:alpha:]]*Hello[[:alpha:]]*");
	string input_str1;
	cin >> input_str1;
	if (regex_search(input_str1, r1)) {
		cout << "success" << endl;
	}
	else {
		cout << "fail" << endl;
	}



	/*
	* 3、正则替换
	在正则查找的基础上，将对应的部分替换为指定字符串
	例如，将52aHellob25替换为52World25
	调用regex_replace函数：
	regex_replace(字符串， 正则表达式，替换后的字符串部分)函数，它返回一个string字符串对象
	*/
	string S3 = "Hello";
	regex r3("[[:alpha:]]*Hello[[:alpha:]]*");
	string new_str3 = regex_replace("52aHellob25", r3, "World");
	cout << new_str3 << endl;
}

int main()
{
	test_regex();

	system("pause");
	return 0;
}

