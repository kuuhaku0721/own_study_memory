/*
* 编写一个程序，定义一个作者及其作品的multimap，使用find在multimap中查找一个元素并用erase删除它
* 确保你的程序在元素不在map中时也能正常运行
* 
* 练习multimap的插入，查找和删除
*/
#include <iostream>
#include <string>
#include<map>
#include<algorithm>
using namespace std;

void remove_author(multimap<string, string>& books, const string& author)
{
	auto pos = books.equal_range(author); //查找给定作者范围
	if (pos.first == pos.second) //空范围，没有该作者
	{
		cout << "没有" << author << "这个作者" << endl << endl;
	}
	else
	{
		books.erase(pos.first, pos.second); //删除该作者所有著作
	}
}

void print_books(multimap<string, string>& books)
{
	cout << "当前书目包括：" << endl;
	for (auto& book : books)
	{
		cout << book.first << ",《" << book.second << "》" << endl;
	}
	cout << endl;
}

int main()
{
	multimap<string, string> books;
	books.insert({ "Barth, John", "Sot-Weed Factor" });
	books.insert({ "Barth, John", "Lost in the Funhouse" });
	books.insert({ "金庸", "射雕英雄传" });
	books.insert({ "金庸", "天龙八部" });

	print_books(books);

	remove_author(books, "张三");

	remove_author(books, "Barth, John");
	print_books(books);

	system("pause");
	return 0;
}

