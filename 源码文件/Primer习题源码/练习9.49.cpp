/*
* 如果一个字母延伸到中线之上如d和f称其有上出头部分，如果在中线之下如p和q，称其有下出头部分
* 编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词
*/
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

void find_longest_word(ifstream& in)
{
	string s, longest_word;
	int max_length = 0;
	while (in >> s)
	{
		if (s.find_first_of("bdfghjklpqty") != string::npos)
		{
			continue; //包含上下出头部分
		}
		cout << s << " ";
		if (max_length < s.size()) //新单词更长
		{
			max_length = s.size(); //记录长度和单词
			longest_word = s;
		}
	}
	cout << endl << "最长字符串：" << longest_word << endl;
}

int main(int argc, char *argv[]) //这是啥看不懂,但是可以用单纯的字符串进行测试
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "无法打开输入文件" << endl;
		return -1;
	}
	find_longest_word(in);

	system("pause");
	return 0;
}

