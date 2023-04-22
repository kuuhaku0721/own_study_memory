#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
* 包含头文件<numeric>
* fill(begin, end, value)
* 向容器中填充元素， value 填充的值
*/
void test01()
{
	vector<int> v;
	v.resize(10);

	//后期重新填充
	fill(v.begin(), v.end(), 888);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
int main()
{

	test01();



	system("pause");
	return 0;
}
