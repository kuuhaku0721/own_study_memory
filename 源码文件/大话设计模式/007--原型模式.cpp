#include <iostream>
#include <string>
using namespace std;
/*
* 原型模式
* 用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
*/
/*
* 这个好像是用在.NET里面的，因为用到了ICloneable接口和clone方法，这些不是自己写的而是库里提供的，所以就不再做实现了
* 感觉应该就是浅拷贝和深拷贝
* 或者也可以是，重载=
*/

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

