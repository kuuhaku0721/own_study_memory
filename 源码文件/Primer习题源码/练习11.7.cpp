﻿/*
* 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子的名。
* 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子
*/
#include <iostream>
#include <string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

void add_family(map<string, vector<string>>& families, const string& family)
{
	if (families.find(family) == families.end())
	{
		families[family] = vector<string>(); //?? 啊？
	}
}

void add_child(map<string, vector<string>>& families, const string& family, const string& child)
{
	families[family].push_back(child);
}

int main()
{
	map<string, vector<string>> families;

	add_family(families, "张");
	add_child(families, "张", "强");
	add_child(families, "张", "刚");
	add_child(families, "王", "五");
	add_family(families, "王");

	for (auto f : families)
	{
		cout << f.first << "家孩子：";
		for (auto c : f.second)
		{
			cout << c << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}

