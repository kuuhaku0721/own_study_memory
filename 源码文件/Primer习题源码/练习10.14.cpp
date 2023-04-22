/*
* 编写一个lambda 接受两个int 返回它们的和
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	auto sum = [](int a, int b) {return a + b; };
	cout << sum(1, 1) << endl; //1+1=2

	system("pause");
	return 0;
}

