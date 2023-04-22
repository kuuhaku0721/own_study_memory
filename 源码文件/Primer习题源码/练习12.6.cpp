/*
* 编写函数，返回一个动态分配的int的vector，将此vector传递给另一个函数，这个函数读取标准输入，将读入的值
* 保存在vector元素中。再将vector传递给另一个函数，打印读入的值。
* 记得在恰当的时刻delete vector
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<int>* new_vector(void)
{
	return new (nothrow)vector<int>;
}
void read_ints(vector<int>* pv)
{
	int v;
	while (cin >> v)
	{
		pv->push_back(v); //vector存的int，读取到非int就停
	}
}
void print_ints(vector<int>* pv)
{
	for (const auto& v : *pv)
	{
		cout << v << " ";
	}
	cout << endl;
}

int main()
{
	vector<int>* pv = new_vector();
	if (!pv)
	{
		cout << "内存不足！" << endl;
		return -1;
	}
	read_ints(pv);
	print_ints(pv);

	delete pv;
	pv = nullptr;

	system("pause");
	return 0;
}

