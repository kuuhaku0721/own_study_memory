/*
* 求杨辉三角的前n行
* 杨辉三角，本质上是二项式(a+b)的 n 次方展开后各项的系数排成的三角形。其性质包括：每行的端点数为 1， 一个数也为 1；
* 每个数等于它左上方和上方的两数之和。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void yangHui()
{
	cout << "请输入想要输出的杨辉三角的层数：";
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> a(i + 1);
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				a[j] = 1;
			}
			else
			{
				a[j] = v[i - 1][j - 1] + v[i - 1][j];
			}
		}
		v.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	yangHui();

	system("pause");
	return 0;
}

