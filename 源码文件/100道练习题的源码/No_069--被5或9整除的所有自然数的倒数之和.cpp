/*
* 计算并输出 n(包括 n)以内能被 5 或 9 整除的所有自然数的倒数之和
*/
#include <iostream>
#include <string>
using namespace std;
void daoshu59()
{
	cout << "请输入n的值：";
	int n;
	cin >> n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 5 == 0 || i % 9 == 0)
		{
			sum += (1.0 / i);
		}
	}
	cout << "结果:" << sum << endl;
}
int main()
{
	daoshu59();

	system("pause");
	return 0;
}

