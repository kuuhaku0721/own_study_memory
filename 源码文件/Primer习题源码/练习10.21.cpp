/*
* 编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0.一旦变量变为0，再调用lambda应该不再递减变量。
* lambda应该返回一个bool值，指出捕获的变量是否为0
*/
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void mutable_lambda(void)
{
	int i = 5;
	auto f = [i]()mutable -> bool {if (i > 0) { i--; return false; } else return true; };

	for (int j = 0; j < 6; j++)
	{
		cout << f() << " ";
	}
	cout << endl;
}

int main()
{
	mutable_lambda();

	system("pause");
	return 0;
}

