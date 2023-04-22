/*
* 矩阵，寻找最高身高输出索引下标
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
void maxHeight()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<int> v1;          //m个默认值为0--匿名对象
	vector<vector<int>> v(n, vector<int>(m));
	int maxn = 0, maxm = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int height;
			cin >> height;
			v[i][j] = height;
			if (v[i][j] >= v[maxn][maxm])
			{
				maxn = i;
				maxm = j;
			}
		}
	}
	cout << "最高的是：" << v[maxn][maxm] << endl;
	//用find算法返回的迭代器,不会搞，二维迭代器转俩数字
}
int main()
{
	maxHeight();

	system("pause");
	return 0;
}

