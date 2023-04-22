/*
* 计算BMI指数
*/
#include <iostream>
#include <string>
#include<math.h>
#include<iomanip>
using namespace std;
void BMI(int kg, int height)
{
	//体重（kg） / 身高（m）的平方
	//结果保留两位小数
	double bmi = kg / pow((height / 100), 2);
	cout << "BMI指数是：";
	cout << fixed << setprecision(2) << bmi << endl;
}
int main()
{
	int kg, height;
	cout << "请输入体重(kg)和身高(m): ";
	cin >> kg >> height;
	BMI(kg, height);

	system("pause");
	return 0;
}

