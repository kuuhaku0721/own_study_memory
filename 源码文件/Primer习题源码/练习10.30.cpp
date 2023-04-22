/*
* 使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，并将结果写到标准输出
* 
* 练习输出流迭代器的使用
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
	//创建流迭代器从标准输入读入整数
	istream_iterator<int> in_iter(cin); //文件流变成标准输入流
	//尾后迭代器
	istream_iterator<int> eof;

	vector<int> v;
	while (in_iter != eof)
	{
		v.push_back(*in_iter++); //存入vector并递增迭代器
	}
	sort(v.begin(), v.end());

	ostream_iterator<int> out_iter(cout, " ");
	copy(v.begin(), v.end(), out_iter);



	system("pause");
	return 0;
}

