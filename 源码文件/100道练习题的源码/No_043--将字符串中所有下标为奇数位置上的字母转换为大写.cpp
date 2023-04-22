/*
* 请编写一个函数 fun，它的功能是：将 ss 所指字符串中所有下标为奇数位置上的
* 字母转换为大写(若该位置上不是字母，则不转换)
*/
#include <iostream>
#include <string>
using namespace std;
void func()
{
	cout << "请输入字符串：" << endl;
	string ss;
	cin >> ss;
	for (int i = 0; i < ss.size(); i=i+2)
	{
		if (ss[i] >= 'a' && ss[i] <= 'z')
		{
			ss[i] -= 32;
		}
	}
	cout << ss << endl;
}
int main()
{
	func();

	system("pause");
	return 0;
}

