/*
* 编写函数 int fun(int lim,int aa[max]),该函数的功能是求出小于或等于 lim 的
* 所有素数并放在 aa 数组中，该函数返回所求的素数的个数
*/
/*
* 0和1 既不是素数也不是合数
*/
#include <iostream>
#include <string>
#include<vector>
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
void fun()
{
	cout << "请输入最大值：";
	int lim;
	cin >> lim;
	vector<int> v;
	for (int i = 2; i <= lim; i++)
	{
		if (sushu(i))
		{
			v.push_back(i);
		}
	}
	cout << "个数：" << v.size() << endl;
}
int main()
{
	fun();

	system("pause");
	return 0;
}

