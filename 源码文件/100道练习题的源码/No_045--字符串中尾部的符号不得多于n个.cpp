/*
* 假定输入的字符串中只包含字母和*号。请编写函数 fun，它的功能是：使字符串
* 中尾部的*号不得多于 n 个；若多于 n 个，则删除多于的*号；若少于或等于 n
* 个，则什么也不做，字符串中间和前面的*号不删除。
*/
#include <iostream>
#include <string>
using namespace std;
void noMore()
{
	//假设不多于3个
	cout << "请输入字符串以*结尾：" << endl;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == '*')
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if (cnt > 3)
	{
		s.erase(s.size() - 1, cnt - 3);
		cout << s << endl;
		cout << "删除了" << cnt - 3 << "个*" << endl;
	}
	else
	{
		cout << s << endl;
	}
}
int main()
{
	noMore();

	system("pause");
	return 0;
}

