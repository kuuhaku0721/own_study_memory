/*
* 将 m 行 n 列的二维数组中的数据，按行的顺序
* 依次放到一维数组中，一维数组中数据的个数存放在形参 n 所指的储存单元中
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void twoOne()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	cout << "请输入矩阵的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	//可以用数组，大小设定n*m，这里就习惯性使用vector
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			v2.push_back(v[i][j]);
		}
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	twoOne();

	system("pause");
	return 0;
}

