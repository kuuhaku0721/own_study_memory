/*
* 编写一个类令其检查某个给定的string对象的长度是否与一个阈值相等
* 使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个，长度为2的单词有多少个，，，，，长度为10的单词有多少个
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

class StrLenIs
{
public:
	StrLenIs(int len) : len(len) {}
	bool operator()(const string& str)
	{
		return str.length() == len;
	}
private:
	int len;
};

void readStr(istream& is, vector<string>& vec)
{
	string word;
	while (is >> word)
	{
		vec.push_back(word);
	}
}

int main()
{
	vector<string> vec;
	readStr(cin, vec);
	const int minLen = 1;
	const int maxLen = 10;
	for (int i = minLen; i <= maxLen; i++)
	{
		StrLenIs slenIs(i);
		cout << "len：" << i << ", cnt: " << count_if(vec.begin(), vec.end(), slenIs) << endl;
	}

	system("pause");
	return 0;
}

