/*
* 编写程序，实现矩阵(3 行 3 列)的转置(即行列互
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void metrixChange(vector<vector<int>>& v)
{
	cout << "之前" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	vector<vector<int>> v1(3,vector<int>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v1[i][j] = v[j][i];
		}
	}
	v = v1;
	v1.clear();
	cout << endl << "之后" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector<vector<int>> v(3,vector<int>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v[i][j] = i + 11;
		}
	}
	metrixChange(v);

	system("pause");
	return 0;
}

