#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//普通函数
void print01(int val)
{
	cout << val << " ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each 参数：起始迭代器，末尾迭代器，一个函数(或者仿函数)只放名字
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//普通函数放函数名，仿函数放函数对象(就是加小括号)
	for_each(v.begin(), v.end(), print02());
	cout << endl;

}

int main()
{

	test01();



	system("pause");
	return 0;
}
