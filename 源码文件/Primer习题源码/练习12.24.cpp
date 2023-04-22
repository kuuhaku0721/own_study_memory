/*
* 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中
* 描述你的程序如何处理变长输入。
* 测试你的程序，输入一个超出你分配的数组长度的字符串
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c;

	//分配20个字符的动态数组
	//因此最多存放19个字符
	char* r = new char[20];
	int i = 0;

	while (cin.get(c))
	{
		if (isspace(c))
			break; //空格符，制表符等空白符
		r[i++] = c; //存入动态数组
		if (i == 20) //已经读入19个
			cout << "达到数组容量上限" << endl;
		break;
	}
	r[i] = 0;
	cout << r << endl;

	//释放动态数组
	delete[] r;

	system("pause");
	return 0;
}

