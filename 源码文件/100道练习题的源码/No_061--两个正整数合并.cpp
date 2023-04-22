/*
* 编写一个函数 fun，其功能是：将两个两位数的正整数 ab 合并形成一个整数放在 c
中。合并方式是：将 a 数的十位和个位数依次放在 c 数的个位和百位上，b 数的十
位和个位数依次放在 c数的十位和千位上。
*/
#include <iostream>
#include <string>
using namespace std;
void unionNum()
{
	cout << "请输入正整数a和b：" << endl;
	int a, b;
	cin >> a >> b;
	int c;
	c = (a % 10) * 100 + (a / 10) + (b / 10) * 10 + (b % 10) * 1000;
	cout << "结果：" << c << endl;
}
int main()
{
	unionNum();

	system("pause");
	return 0;
}

