/*
* 编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序
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
//               条款××  经常使用const
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
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
//                                          二元谓词
	stable_sort(words.begin(), words.end(), isShorter);
	output_words(words);
}

int main()
{
	vector<string> v = { "hello", "world", "hello", "Java World", "Ciallo", "Phython" };
	elimDups(v);

	system("pause");
	return 0;
}

