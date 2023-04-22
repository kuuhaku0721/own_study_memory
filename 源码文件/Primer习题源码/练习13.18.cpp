/*
* 定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。
* 为这个类定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数
* 每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。
* 
* 练习定义拷贝构造成员
*/
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
	static int sn;
public:
	Employee() { mysn = sn++; }
	Employee(const string& s) { name = s; mysn = sn++; }

	//如果加一个拷贝构造函数和拷贝构造运算符
	Employee(Employee& e) { name = e.name; mysn = sn++; }
	Employee& operator=(Employee& rhs) { name = rhs.name; return *this; }

	const string& get_name() { return name; }
	int get_mysn() { return mysn; }
private:
	string name;
	int mysn;
};
int Employee::sn = 0;

void f(Employee& s)
{
	cout << s.get_name() << ": " << s.get_mysn() << endl;
}

int main()
{
	Employee a("赵"), b = a, c;
	//没加两个拷贝函数的时候输出是三个0，static并没有自增
	//加上两个拷贝函数，static能够正确自增，so，why?
	//因为如果不自己定义，默认生成的拷贝函数只是简单地复制，使两个对象值相等
	c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}

