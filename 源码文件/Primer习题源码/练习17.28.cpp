﻿/*
* 编写函数，每次调用生成并返回一个均匀分布的随机unsigned int，允许用户提供一个种子作为可选参数
*/
#include <iostream>
#include <string>
#include<random>
using namespace std;

unsigned int rand_int(long seed = -1)
{
	//生成0到9999之间（包含）均匀分布的随机数
	static uniform_int_distribution<unsigned> u(0, 9999);
	static default_random_engine e; //生成无符号随机整数

	if (seed >= 0)
		e.seed(seed);
	return u(e);
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << rand_int() << " ";
	cout << endl;

	cout << rand_int(0) << " ";
	for (int i = 0; i < 9; i++)
		cout << rand_int() << " ";
	cout << endl;

	cout << rand_int(19743) << " ";
	for (int i = 0; i < 9; i++)
		cout << rand_int() << " ";
	cout << endl;

	system("pause");
	return 0;
}

