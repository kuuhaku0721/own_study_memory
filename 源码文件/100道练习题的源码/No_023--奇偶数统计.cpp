/*
* 任意输入一个正整数 N，统计 1~N 之间奇数的个数和偶数的个数，并输出。
*/
#include <iostream>
#include <string>
using namespace std;
void doubleSingle()
{
	cout << "请输入数字N：";
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << "奇数个数：" << n / 2 << endl;
		cout << "偶数个数：" << n / 2 << endl;
	}
	else
	{
		cout << "奇数个数：" << (n + 1) / 2 << endl;
		cout << "偶数个数：" << (n - 1) / 2 << endl;
	}
}
int main()
{
	doubleSingle();

	system("pause");
	return 0;
}

