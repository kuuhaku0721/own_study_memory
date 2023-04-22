/*
* 第一行包含两个整数 n 和 m，表示一个矩阵包含 n 行 m 列，用空格分隔。 (1≤n≤10,1≤m≤10)
从 2 到 n+1 行，每行输入 m 个整数，用空格分隔，共输入 n*m 个数，表示第一个矩阵中的元素。
接下来一行输入 k，表示要执行 k 次操作（1≤k≤5）。接下来有 k 行，每行包括一个字符 t 和两个数 a 和 b，中间用空格
格分隔，t 代表需要执行的操作，当 t 为字符'r'时代表进行行变换，当 t 为字符'c'时代表进行列变换，a 和 b 为需要互
换的行或列（1≤a≤b≤n≤10，1≤a≤b≤m≤10）。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Change
{
public:
	Change(char change, int n, int m)
	{
		this->change = change;
		this->n = n - 1;
		this->m = m - 1;
	}
	char change;
	int n;
	int m;
};
void metrixChange()
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
	cout << "请输入想要进行的操作的次数：";
	int cnt;
	cin >> cnt;
	cout << "请分行输入操作指令：" << endl;
	vector<Change> vc;
	for (int i = 0; i < cnt; i++)
	{
		char t;
		int n, m;
		cin >> t >> n >> m;
		Change ca(t, n, m);
		vc.push_back(ca);
	}
	//默认输入数据都合法
	for (vector<Change>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		if ((*it).change == 'r' || (*it).change == 'R')
		{
			//行变换
			vector<int> temp;
			temp = v[(*it).n];
			v[(*it).n] = v[(*it).m];
			v[(*it).m] = temp;
		}
		else if ((*it).change == 'c' || (*it).change == 'C')
		{
			//列变换
			int temp;
			for (int i = 0; i < n; i++)
			{
				temp = v[i][(*it).n];
				v[i][(*it).n] = v[i][(*it).m];
				v[i][(*it).m] = temp;
			}
		}
		else
		{
			cout << "输入指令有误" << endl;
			return;
		}
	}
	//输出
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	metrixChange();

	system("pause");
	return 0;
}

