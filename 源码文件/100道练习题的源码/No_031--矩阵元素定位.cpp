/*
* 了一个 n 行 m 列的矩阵，现在他想知道第 x 行第 y 列的值是多少
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
/*
* 问题：如果用二维数组，需要提前设定数组大小，数组只能用常量确定，没法后期更改，这样会造成很多的内存浪费
* 如果用vector的嵌套形成一个二维数组，基于vector特性可以不管列但是需要提前知道有几行，决定创建几个子容器，会过度占用时间
* 要么空间复杂度大，要么时间复杂大
* 这里牺牲时间换空间，只要联系容器的使用
*   |  |  |
*   |  |  |
*   |  |  |
*   V  V  V
* 问题已解决  匿名对象实现二维数组 vector<vector<int>> v(n, vector<int>(m));  实现的效果v[n][m];
*/
void matrixLocate()
{
	cout << "请确定矩阵n行m列：" << endl;
	int n, m;
	cin >> n >> m;
	vector<int> v1;          //m个默认值为0--匿名对象
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	cout << "请输入要查找的位置[n][m]:";
	int n1, m1;
	cin >> n1 >> m1;
	cout << "位置[" << n1 << "][" << m1 << "]处值为：" << v[n1-1][m1-1] << endl;
}
int main()
{
	matrixLocate();

	system("pause");
	return 0;
}

