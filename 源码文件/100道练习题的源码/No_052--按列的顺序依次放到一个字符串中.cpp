/*
* 将 m 行 n 列的二维数组中的字符数据，按列的顺序依次放到一个字符串中。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void columnToStr()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	string str;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			str += v[j][i];
		}
	}
	cout << str << endl;
}
int main()
{
	columnToStr();

	system("pause");
	return 0;
}

