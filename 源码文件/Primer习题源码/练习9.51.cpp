/*
* 设计一个类，有三个unsigned成员分别表示年月日，编写构造函数，接受一个表示日期的string参数、
* 构造函数能处理不同的数据格式如 January 1,1900 1/1/1900  Jan 1 1900 等
*/
#include <iostream>
#include <string>
#include"date.h"
using namespace std;
/*执行不了，可能缺少一些什么依赖库，但是.h中用到的东西有点超纲看不懂了*/
int main()
{
	string dates[] = { "Jan 1,2014", "February 1 2014", "3/1/2014", "Jcn 1,2014", "Janvary 1,2014", "Jan 32,2014", "Jan 1/2014", "3 1 2014" };
	try
	{
		for (auto ds : dates)
		{
			date d1(ds);
			cout << d1;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}

