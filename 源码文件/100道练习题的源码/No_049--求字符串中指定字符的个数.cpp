/*
* 请编写函数 fun，它的功能是：求出 ss 所指字符串中指定字符的个数，并返回此值
*/
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
void statisticsSS()
{
	cout << "请输入字符串：" << endl;
	string ss;
	cin >> ss;
	cout << "请输入想要统计的字符：";
	char c;
	cin >> c;
	int cnt = count(ss.begin(), ss.end(), c);
	cout << "个数：" << cnt << endl;
}
int main()
{
	statisticsSS();

	system("pause");
	return 0;
}

