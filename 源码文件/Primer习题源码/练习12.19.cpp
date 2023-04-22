﻿/*
* 定义自己版本的StrBlobPtr 更新StrBlob类，加入恰当的friend声明及begin和end成员
*/
#include <iostream>
#include <string>
using namespace std;

#include"my_StrBlob.h"

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	const StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
	{
		cout << it.deref() << endl;
	}

	system("pause");
	return 0;
}

