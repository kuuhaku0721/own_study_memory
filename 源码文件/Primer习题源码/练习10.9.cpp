/*
* 编写函数 测试unique的作用
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

inline void output_words(vector<string>& words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void elimDups(vector<string>& words)
{
	output_words(words);

	sort(words.begin(), words.end());
	output_words(words);

	auto end_unique = unique(words.begin(), words.end());
	output_words(words);

	words.erase(end_unique, words.end());
	output_words(words);
}

int main()
{
	vector<string> v = { "hello", "world", "hello", "Java World", "Ciallo", "Phython" };
	elimDups(v);

	system("pause");
	return 0;
}

