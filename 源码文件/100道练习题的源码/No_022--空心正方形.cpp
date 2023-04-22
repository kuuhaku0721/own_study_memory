/*
* 陈友铭学习了循环，Bingo 老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的“空心”正方形图案
*/
#include <iostream>
#include <string>
using namespace std;
void square()
{
	cout << "请输入边长数：";
	int n;
	cin >> n;
	if (n == 1) cout << "*" << endl;
	if (n == 2) cout << "**" << endl << "**" << endl;
	//最上
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	cout << endl;
	for (int i = 0; i < n-2; i++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || i == n - 1)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	cout << endl;
}
int main()
{
	square();

	system("pause");
	return 0;
}

