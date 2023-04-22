/*
* 编写函数 fun()，它的功能是求 n 以内(不包括 n)同时能被 3 与 7 整除的所有自然
* 数之和的平方根 s，并做为函数值返回。例如：n 为 1000 时，函数值应为 s＝
* 153.909064
*/
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
void func()
{
	cout << "请输入n：";
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 3 == 0 && i % 7 == 0)
		{
			sum += i;
		}
	}
	double res = sqrt(sum);
	cout << "结果：" << res << endl;
}
int main()
{
	func();

	system("pause");
	return 0;
}

