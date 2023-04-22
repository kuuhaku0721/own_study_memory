/*
* 计算并输出 3 到 n 之间所有素数的平方根之和
*/
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
bool sushu(int n)
{
	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void sushuSum()
{
	cout << "请输入范围n：";
	int n;
	cin >> n;
	double sum = 0.0;
	for (int i = 3; i <= n; i++)
	{
		if (sushu(i))
		{
			sum += sqrt(i);
		}
	}
	cout << "结果：" << sum << endl;
}
int main()
{
	sushuSum();

	system("pause");
	return 0;
}

