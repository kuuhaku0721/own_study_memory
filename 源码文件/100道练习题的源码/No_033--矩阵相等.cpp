/*
* 判断两个矩阵是否相等 即两个矩阵是否完全相同
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void metrixEqual()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v1(n, vector<int>(m));
	vector<vector<int>> v2(n, vector<int>(m));
	cout << "请输入第一个矩阵的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v1[i][j];
		}
	}
	cout << "请输入第二个矩阵的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v2[i][j];
		}
	}
	cout << "结果：" << endl;
	for (vector<vector<int>>::iterator it = v1.begin(), it2 = v2.begin(); it != v1.end(); it++, it2++)
	{
		if (*it != *it2)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}
int main()
{
	metrixEqual();

	system("pause");
	return 0;
}

