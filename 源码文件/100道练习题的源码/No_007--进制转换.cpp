/*
* 输入一个十六进制和一个八进制，计算和并输出其十进制结果
* oct为八进制，hex为十六进制，dec为十进制
*/
#include <iostream>
#include <string>
using namespace std;
void sumOH(int a, int b)
{
	cout << "和为：" << dec << a + b << endl;
}
int main()
{
	cout << "请输入数字：" << endl;
	int a, b;
	cin >> hex >> a;
	cin >> oct >> b;
	sumOH(a, b);

	system("pause");
	return 0;
}

