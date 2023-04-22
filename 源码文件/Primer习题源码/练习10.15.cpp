/*
* 编写一个lambda，捕获它所在函数的int，并接受一个int参数，lambda应该返回捕获的int和int参数的和
*/
#include <iostream>
#include <string>
using namespace std;

void add(int a)
{
	//  捕获的参数|传参
	auto sum = [a](int b) {return a + b; };
	cout << sum(1) << endl;
}

int main()
{
	add(1);
	add(2);

	system("pause");
	return 0;
}

