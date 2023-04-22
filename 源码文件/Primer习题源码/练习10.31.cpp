/*
* 修改上一个程序，使其只打印不重复的元素，程序应该使用unique_copy
* 
* 练习流迭代器和unique_copy的使用
*/
#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	//创建流迭代器从标准输入读入整数
	istream_iterator<int> in_iter(cin);
	//尾后迭代器
	istream_iterator<int> eof;
	
	vector<int> v;
	while (in_iter != eof)
	{
		v.push_back(*in_iter++); //存入vector并递增迭代器
	}

	sort(v.begin(), v.end());

	ostream_iterator<int> out_iter(cout, " ");
	unique_copy(v.begin(), v.end(), out_iter);


	system("pause");
	return 0;
}

