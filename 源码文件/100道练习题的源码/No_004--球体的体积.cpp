/*
* 计算球体的体积
* 结果保留三位小数
*/
#include<iomanip>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
#define PI 3.1415926
void ball(double r)
{
	double V = (4 * PI * pow(r, 3)) / 3;
	cout << "球的体积为：" << fixed << setprecision(3) << V << endl;
}
int main()
{
	cout << "请输入球的半径：";
	double r;
	cin >> r;
	ball(r);

	system("pause");
	return 0;
}

