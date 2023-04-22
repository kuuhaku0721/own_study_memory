#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
* 包含头文件<numeric>
* accumulate(begin, end, value)
* 计算容器元素累计总和， value起始值
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//计算总和
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "总和是：" << total << endl;
}
int main()
{

	test01();



	system("pause");
	return 0;
}
