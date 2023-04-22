/*
* 计算并输出给定 10 个数的方差
*/
#include <iostream>
#include <string>
#include<vector>
#include<math.h>
using namespace std;
void variance()
{
	cout << "请依次输入10个数：" << endl;
	vector<float> v;
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	float sum = 0.0;
	double avg = 0.0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	avg = sum / 10;
	sum = 0.0;
	for (vector<float>::iterator it = v.begin(); it != v.end(); it++)
	{
		sum += pow(avg - *it, 2);
	}
	cout << "方差结果为：" << sum / 10 << endl;
}
int main()
{
	variance();

	system("pause");
	return 0;
}

