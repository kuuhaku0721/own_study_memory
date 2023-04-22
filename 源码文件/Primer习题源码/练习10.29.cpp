/*
* 编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里
* 
* 练习流迭代器的简单实用
*/
#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	ifstream in;
	if (!in)
	{
		cout << "打开文件失败！" << endl;
		exit(1);
	}

	//创建流迭代器从文件读取字符串
	istream_iterator<string> in_iter(in);
	//尾后迭代器
	istream_iterator<string> eof;
	vector<string> words;
	while (in_iter != eof)
	{
		words.push_back(*in_iter++); //存入vector并递增迭代器
	}

	for (auto word : words)
	{
		cout << word << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}

