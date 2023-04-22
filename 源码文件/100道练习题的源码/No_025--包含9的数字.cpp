/*
* 1~2019 中有多少个包含数字 9 的数。包含数字的数是指有某一位是“9”的数，例
如“2019”、“299”等
*/
#include <iostream>
#include <string>
using namespace std;
void include9()
{
	cout << "1--2023之间包含9的数字有：" << endl;
	int cnt = 0;
	for (int i = 1; i <= 2023; i++)
	{
		int temp = i;
		while (temp > 0)
		{
			int n = temp % 10;
			if (n == 9)
			{
				cout << i << " ";
				cnt++;
				if (cnt % 10 == 0) cout << endl;
				break;
			}
			temp /= 10;
		}
	}
	cout << endl << "一共有：" << cnt << " 个" << endl;
}
int main()
{
	include9();

	system("pause");
	return 0;
}

