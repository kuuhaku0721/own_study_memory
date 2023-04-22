/*
* 标准库定义了名为partition的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分
* 而谓词为false的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置。
* 测试partition 练习使用一元谓词 判断string对象长度是否大于等于5
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
	for (auto iter = beg; iter != end; iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

bool five_or_more(const string& s1)
{
	return s1.size() >= 5;
}

int main()
{
	vector<string> v = { "hello", "world", "llo", "Java", "Ciallo", "Phython" };
	output_words(v.begin(), v.end());

	auto iter = partition(v.begin(), v.end(), five_or_more);
	output_words(v.begin(), iter);

	system("pause");
	return 0;
}

