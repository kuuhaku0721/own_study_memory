/*
* 陈友铭学习了循环，Bingo 老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的 X 形图案。
*/
#include <iostream>
#include <string>
using namespace std;
void x()
{
	cout << "请输入层数：";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || i + j == n + 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	x();

	system("pause");
	return 0;
}

