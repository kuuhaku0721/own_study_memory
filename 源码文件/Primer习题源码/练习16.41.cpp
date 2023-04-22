/*
* 编写一个新的sum版本，它的返回类型保证足够大，足以容纳加法结果
* 
* 练习定义尾置返回类型
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	auto a = sum(1, 1);  //结果以大的为准 int + int = int
	cout << a << " " << sizeof(a) << endl;
	auto b = sum(1, 9.8); //int + double = double
	cout << b << " " << sizeof(b) << endl;
	auto c = sum(1, 2.3f); //int + float = float
	cout << c << " " << sizeof(c) << endl;

	system("pause");
	return 0;
}

