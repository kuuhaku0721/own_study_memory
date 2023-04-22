/*
* 计算三角形的周长和面积，给出三条边,保留两位小数
*/
#include <iostream>
#include <string>
#include<math.h>
#include<iomanip>
using namespace std;
void triangleCS(int a, int b, int c)
{
	//p=周长一半 面积=根号下p*p-a*p-b*p-c
	double circle = a + b + c;
	double p = circle / 2;
	double S = p * (p - a) * (p - b) * (p - c);
	double area = sqrt(S);
	cout << "周长：" << fixed << setprecision(2) << circle << endl;
	cout << "面积：" << fixed << setprecision(2) << area << endl;
}
int main()
{
	cout << "请输入三角形的三条边：";
	int a, b, c;
	cin >> a >> b >> c;
	triangleCS(a, b, c);

	system("pause");
	return 0;
}

