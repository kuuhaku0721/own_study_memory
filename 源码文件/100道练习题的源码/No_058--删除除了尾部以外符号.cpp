/*
* 假定输入的字符串中只包含字母和*号。请编写函数 fun，它的功能是：除了尾部
* 的*号之外，将字母串中其他*号全部删除。形参 p 已指向字符串中最后的一个字
* 母。不使用 c 的字符串函数
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void delete8()
{
	//除了末尾全删？那就所有*全删然后再给末尾加上
	cout << "请输入字符串：" << endl;
	string s;
	cin >> s;
	int num = 0;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == '*')
		{
			num++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			s.erase(i, 1);
			i--;
		}
	}
	for (int i = 0; i < num; i++)
	{
		s += "*";
	}
	cout << s << endl;
}
int main()
{
	delete8();

	system("pause");
	return 0;
}

