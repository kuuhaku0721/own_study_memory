/*
* 根据以下公式求 p 的值，结果由函数值带回。M与 n 为两个正整数，且要求 m>n。 p=m!/n!(m-n)
*/
#include <iostream>
#include <string>
using namespace std;
int jiecheng(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return n * jiecheng(n - 1);
	}
}
void forNUm()
{
	cout << "请输入两个整数m和n：" << endl;
	int m, n;
	cin >> m >> n;
	double res = jiecheng(m) / (jiecheng(n) * (m - n));
	cout << "结果：" << res << endl;
}
int main()
{
	forNUm();

	system("pause");
	return 0;
}

