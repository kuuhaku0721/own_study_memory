/*
* 输入 10 个整数，分别统计输出正数、负数的个数。
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
//大于0的谓词
class greaterZero
{
public:
	bool operator()(int val)
	{
		if (val >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void positiveNegative()
{
	cout << "请输入10个数据：" << endl;
	//可以算法的count统计，结合谓词使用
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}//                                       带括号，传匿名对象
	int positive = count_if(v.begin(),v.end(),greaterZero());
	int negative = v.size() - positive;
	cout << "正数个数：" << positive << endl;
	cout << "负数个数：" << negative << endl;
}
int main()
{
	positiveNegative();

	system("pause");
	return 0;
}

