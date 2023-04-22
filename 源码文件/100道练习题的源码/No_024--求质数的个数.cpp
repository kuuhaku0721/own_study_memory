/*
* 所有三位整数中，有多少个质数。
*/
#include <iostream>
#include <string>
using namespace std;
bool pd(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
void zhishu()
{
	int cnt = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i == 1 || i == 2 || i == 3)
		{
			cout << i << " ";
			cnt++;
		}
		else
		{
			if (pd(i))
			{
				cout << i << " ";
				cnt++;
				if (cnt % 10 == 0)
				{
					cout << endl;
				}
			}
		}
	}
	cout << endl << "三位数以内的质数一共有：" << cnt << " 个" << endl;
}
int main()
{
	zhishu();

	system("pause");
	return 0;
}

