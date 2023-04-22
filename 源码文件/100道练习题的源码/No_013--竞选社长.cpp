/*
* 假设你们社团要竞选社长，有两名候选人分别是 A 和 B，社团每名同学必须并且只能投一票，最终得票多的人为社长
* 输入一行，字符序列，包含 A 或 B，输入以字符 0 结束。
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void vote()
{
	cout << "请输入投的票（以0结束）：" << endl;
	vector<char> v;
	char c;
	for (int i = 0;; i++)
	{
		cin >> c;
		if (c == '0') break;
		v.push_back(c);
	}
	int a = 0, b = 0,other = 0;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it) == 'A')
		{
			a++;
		}
		else if ((*it) == 'B')
		{
			b++;
		}
		else
		{
			other++;
		}
	}
	cout << "A票数：" << a << endl;
	cout << "B票数：" << b << endl;
	cout << "无效票：" << other << endl;
	char vectory = a > b ? 'A' : 'B';
	cout << "当选者：" << vectory << endl;
}
int main()
{
	vote();

	system("pause");
	return 0;
}

