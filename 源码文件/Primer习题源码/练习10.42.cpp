/*
* 使用list实现去除重复单词的程序
*/
#include <iostream>
#include <string>
#include<list>
#include<algorithm>
using namespace std;

inline void output_words(list<string>& words)
{
	for (auto it = words.begin(); it != words.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void elimDups(list<string>& words)
{
	output_words(words);

	words.sort();
	output_words(words);

	words.unique();
	output_words(words);
}

int main()
{
	list<string> words = { "hello", "world", "hello", "Java", "Ciallo", "Phython" };
	elimDups(words);

	system("pause");
	return 0;
}

