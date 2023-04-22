/*
* 计算并输出下列多项式的值：
* sn=1+1/1!+1/2!+1/3!+1/4!+…+1/n!
*/
#include <iostream>
#include <string>
using namespace std;
int jie(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return n * jie(n - 1);
	}
}
void jiecheng()
{
	cout << "请确定数字n：";
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += jie(i);
	}
	cout << "结果是：" << sum << endl;
}
int main()
{
	jiecheng();

	system("pause");
	return 0;
}

