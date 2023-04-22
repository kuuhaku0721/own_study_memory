/*
* 从键盘输入 a, b, c 的值，编程计算并输出一元二次方程 ax2 + bx + c = 0 的根，当 a = 0 时，输出“Not quadratic
equation”，当 a ≠ 0 时，根据△ = b2 - 4*a*c 的三种情况计算并输出方程的根。
*/
#include <iostream>
#include <string>
#include<iomanip>
#include<math.h>
using namespace std;
void equation()
{
	cout << "请输入Ax2+Bx+C=0中A，B，C的值:" << endl;
	float a, b, c;
	cin >> a >> b >> c;
	if (a == 0) cout << "No answer" << endl;
	double delt = b * b - 4 * a * c;
	if (delt == 0)
	{
		//x1==x2
		cout << "x1=x2= ";
		double res = (-b) / (2 * a);
		cout << fixed << setprecision(2) << res << endl;
	}
	else if (delt > 0)
	{
		//x1 != x2
		double x1 = ((-b) + sqrt(delt)) / (2 * a);
		double x2 = ((-b) - sqrt(delt)) / (2 * a);
		cout << "x1= " << fixed << setprecision(2) << x1 << " x2= " << x2 << endl;
	}
	else
	{
		//实部虚部
		double s = (-b) / (2 * a);
		double x = sqrt(-delt) / (2 * a);
		cout << "x1= " << fixed << setprecision(2) << s << "+" << x << "i" << endl;
		cout << "x2= " << fixed << setprecision(2) << s << "-" << x << "i" << endl;
	}
}
int main()
{
	equation();

	system("pause");
	return 0;
}

