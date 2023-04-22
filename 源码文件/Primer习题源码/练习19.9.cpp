/*
* 编写程序，令其打印你的编译器为一些常见类型所起的名字
* 
* type_info类的使用练习
*/
#include <iostream>
#include <string>
#include<typeinfo>
using namespace std;

class Base {};
class Derived : public Base{};

int main()
{
	Base b, * pb;
	pb = NULL;
	Derived d;

	cout << typeid(int).name() << endl
		<< typeid(unsigned).name() << endl
		<< typeid(long).name() << endl
		<< typeid(unsigned long).name() << endl
		<< typeid(char).name() << endl
		<< typeid(unsigned char).name() << endl
		<< typeid(float).name() << endl
		<< typeid(double).name() << endl
		<< typeid(string).name() << endl
		<< typeid(Base).name() << endl
		<< typeid(b).name() << endl
		<< typeid(pb).name() << endl
		<< typeid(Derived).name() << endl
		<< typeid(d).name() << endl
		<< typeid(type_info).name() << endl;

	system("pause");
	return 0;
}

