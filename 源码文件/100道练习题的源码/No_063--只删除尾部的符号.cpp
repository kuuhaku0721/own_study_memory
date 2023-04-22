/*
* 将字符串尾部的*号全部删除，前面和中间的*号不删除
*/
#include <iostream>
#include <string>
using namespace std;
void deleteTail()
{
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '*')
		{
			s.erase(i, 1);
		}
		else
		{
			break;
		}
	}
	cout << "结果：" << s << endl;
}
int main()
{
	deleteTail();

	system("pause");
	return 0;
}

