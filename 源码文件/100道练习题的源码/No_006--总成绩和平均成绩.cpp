/*
* 依次输入三科成绩，打印总成绩和平均成绩,保留两位小数
*/
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>
using namespace std;
void score(vector<double>& v)
{
	double sum = 0.0;
	for (vector<double>::iterator it = v.begin(); it != v.end(); it++)
	{
		sum += *it;
	}
	cout << "总成绩为：" << fixed  << setprecision(2) << sum << endl;
	cout << "平均成绩为：" << fixed << setprecision(2) << sum / v.size() << endl;
}
int main()
{
	cout << "请输入三科成绩:" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	vector<double> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	score(v);

	system("pause");
	return 0;
}

