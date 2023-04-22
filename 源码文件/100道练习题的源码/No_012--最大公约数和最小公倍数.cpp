/*
* 每组输入包含两个正整数 n 和 m
对于每组输入，输出一个正整数，为n 和 m 的最大公约数与最小公倍数
*/
#include <iostream>
#include <string>
using namespace std;
void multi(int n, int m)
{
	int yue = 0, bei = 0;
	int min = m >= n ? n : m;
	for (int i = min; i >= 1; i--)
	{
		if (n % i == 0 && m % i == 0)
		{
			yue = i;
		}
	}
	for (int i = min; i <= n*m; i++)
	{
		if (i % n == 0 && i % m == 0)
		{
			bei = i;
		}
	}
	cout << "最大公约数：" << yue << endl;
	cout << "最小公倍数：" << bei << endl;
	cout << "两数和：" << yue + bei << endl;
}
int main()
{
	cout << "请输入两个整数：";
	int n, m;
	cin >> n >> m;
	multi(n, m);

	system("pause");
	return 0;
}

