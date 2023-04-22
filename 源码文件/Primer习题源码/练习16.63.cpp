/*
* 定义一个函数模板，统计一个给定值在一个vector中出现的次数
* 测试你的函数，分别传递给它一个double的vector，一个int的vector以及一个string的vector
*/
#pragma warning(disable:4996)  //忽略unsafe报错
#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

template <typename T>
int occur(vector<T>& vec, const T& v)
{
	int ret = 0;
	for (auto a : vec)
	{
		if (a == v)
			ret++;
	}
	return ret;
}

//这就是一个特例化版本 也就是偏特化
template <>
int occur(vector<char*>& vec, char* const& v)
{
	int ret = 0;
	for (auto a : vec)
	{
		if (!strcmp(a, v))
			ret++;
	}
	return ret;
}

int main()
{
	vector<double> vd = { 1.1,3.14,2.2,3.14,3.3,4.4 };
	cout << occur(vd, 3.14) << endl;

	vector<int> vi = { 0,1,2,3,4,5 };
	cout << occur(vi, 0) << endl;

	vector<string> vs = { "Hello", "World", "!" };
	cout << occur(vs, string("end")) << endl;

	vector<char*> vp;
	vp.push_back(new char[6]);
	vp.push_back(new char[6]);
	vp.push_back(new char[2]);
	strcpy(vp[0], "Hello");
	strcpy(vp[1], "World");
	strcpy(vp[2], "!");
	char* w = new char[6];
	strcpy(w, "World");
	cout << occur(vp, w) << endl;

	//记得释放掉内存
	delete w;
	delete vp[2];
	delete vp[1];
	delete vp[0];

	system("pause");
	return 0;
}

