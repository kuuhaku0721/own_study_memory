/*
*大小写字母转换
*/
/*留存的一丢丢问题，题目给的是分行输入，但是没有明确几个所以并没法做到分行输入*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
void change(vector<char>& v)
{
	//输出
	/*
	* algorithm提供了转换大小写的算法
	* string s;
	* transform(s.begin(),s.end(),s.begin(),::tolower);
	*           起始位置  结束位置 转换之后存放位置  toupper tolower
	*/
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it) >= 'a' && (*it) <= 'z')
		{
			//如果是小写就转换成大写
			(*it) -= 32;
		}
		else
		{
			//如果是大写就转换成小写
			(*it) += 32;
		}
		cout << *it << endl;
	}
}
int main()
{
	vector<char> v;
	char letter;
	cout << "请输入字符：(ctrl+Z结束)" << endl;
	while (cin >> letter)
	{
		v.push_back(letter);
		if (cin.get() == '\n')
		{
			cout << "输入结束" << endl;
			break;
		}
	}
	change(v);

	system("pause");
	return 0;
}

