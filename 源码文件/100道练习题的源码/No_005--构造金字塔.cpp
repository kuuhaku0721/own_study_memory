/*
* 输入一个字符，用该字符构造金字塔
*/
/*这个有点问题，题目给的是正三角形金字塔，但是实现只实现了直角三角金字塔*/
#include <iostream>
#include <string>
using namespace std;
void goldenTower(char c, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		for (int j1 = 0; j1 < floor-i; j1++)
		{
			cout << " ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << c;
		}
		cout << endl;
	}
}
int main()
{
	cout << "请输入构造金字塔的字符和金字塔的层数：";
	char c;
	int floor;
	cin >> c >> floor;
	goldenTower(c, floor);

	system("pause");
	return 0;
}

