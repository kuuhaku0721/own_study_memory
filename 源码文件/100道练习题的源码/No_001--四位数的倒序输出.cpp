/*
* 将一个四位数 反序输出
*/
#include <iostream>
#include <string>
using namespace std;
void test01(int num)
{
	//题目给定是四位数，那就直接遍历 取模 输出
	cout << "结果是：";
	for (int i = 0; i < 4; i++)
	{
		cout << num % 10;
		num /= 10;
	}
	cout << endl;
}
void upDown(int num)
{
	//任意位数倒序输出
	cout << "结果是：";
	while (num > 0)
	{
		cout << num % 10;
		num /= 10;
	}
	cout << endl;
}
int main()
{
	int num;
	cout << "请输入数字：";
	cin >> num;
	//test01(num);
	upDown(num);

	system("pause");
	return 0;
}

