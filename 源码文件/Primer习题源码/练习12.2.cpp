/*
* 编写一个StrBlob类，包含const版本的front和back。
* 练习智能指针的简单使用
*/
/*
* 里边用到了好多不认识的东东，应该不算必须掌握项，吧
*/
#include<iostream>
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
	cout << b1.front() << "   " << b1.back() << endl;

	const StrBlob b3 = b1;
	cout << b3.front() << "   " << b3.back() << endl;

	system("pause");
	return 0;
}

