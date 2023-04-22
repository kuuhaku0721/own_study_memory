/*
* 任意输入 a[N][N]个数，找出并输出其中的最大数和最小数，以及它们的下标。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void findMan()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	int maxn = 0, maxm = 0;
	int minn = 0, minm = 0;
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
			if (v[i][j] <= v[minn][minm])
			{
				minn = i;
				minm = j;
			}
		}
	}
	cout << "最大数：" << v[maxn][maxm] << " 下标：" << maxn << " " << maxm << endl;
	cout << "最小数：" << v[minn][minm] << " 下标：" << minn << " " << minm << endl;
}
int main()
{
	findMan();

	system("pause");
	return 0;
}

