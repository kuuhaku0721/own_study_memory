/*
* 给定 n 个整数和一个整数 x，从 n 个整数中判断 x 出现几次
*/
#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;
void findNum()
{
	cout << "请输入个数n：";
	int n;
	cin >> n;
	//有统计算法
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	cout << "请输入想要统计的数字：";
	int value;
	cin >> value;
	int cnt = count(v.begin(), v.end(), value);
	cout << "个数为：" << cnt << endl;
}
int main()
{
	findNum();

	system("pause");
	return 0;
}

