/*
* 程序定义了 n×n 的二维数组，并在主函数中自动赋值。请编写函数 fun,该函数的
* 功能是：使数组左下半三角元素中的值乘以 n
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void multiM(vector<vector<int>>& v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			v[i][j] *= n;
		}
	}
	//输出
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (int i = 0; i < (*it).size(); i++)
		{
			cout << (*it)[i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n = 0, m = 0;
	cout << "确定二维数组大小：" << endl;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			v[i][j] = i + j;
		}
	}
	int N;
	cout << "确认要乘的数n：";
	cin >> N;
	multiM(v, N);

	system("pause");
	return 0;
}

