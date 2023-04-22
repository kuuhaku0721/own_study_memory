/*
* 求出 1 到 100 之内能被 7 或者 11 整除，但不能同
* 时北 7 和 11 整除的所有整数，并将他们放在 a 所指的数组中，通过 n 返回这些数
* 的个数
*/
#include <iostream>
#include <string>
using namespace std;
void nanachu()
{
	cout << "请确定范围：";
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (i % 7 == 0 || i % 11 == 0)
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
int main()
{
	nanachu();

	system("pause");
	return 0;
}




