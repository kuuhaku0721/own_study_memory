/*
* 编写一个程序，连接两个字符串常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象
* 
* 练习使用动态数组
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const char* c1 = "Hello";
	const char* c2 = "World";

	//字符串所需空间等于字符数+1
	char* r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy_s(r, sizeof(c1) + 1, c1); //拷贝第一个字符串常量
	strcat_s(r, sizeof(r) + sizeof(c2) + 1, c2); //连接第二个字符串常量
	cout << r << endl;

	string s1 = "hello";
	string s2 = "world";
	strcpy_s(r, sizeof((s1 + s2).c_str()) + 1, (s1 + s2).c_str()); //拷贝连接结果
	cout << r << endl;

	//释放动态数组
	delete[] r;

	system("pause");
	return 0;
}

