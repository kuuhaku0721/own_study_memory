/*
* 编写一个简单的桌面计算器使其能处理二元运算
*/
#include <iostream>
#include <string>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

map<string, function<int(int, int)>> binOps = {
	{"+", plus<int>()},
	{"-",minus<int>()},
	{"*",multiplies<int>()},
	{"/",divides<int>()},
	{"%",modulus<int>()}
};

int main()
{
	int left, right;
	string op;
	cin >> left >> op >> right;
	cout << binOps[op](left, right) << endl;


	system("pause");
	return 0;
}

