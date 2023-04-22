/*
* Bingo 想知道已经给出的三条边 a，b，c 能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三
角形或普通三角形）
*/
#include <iostream>
#include <string>
using namespace std;
void isTriangle()
{
	cout << "请输入三角形的三条边：" << endl;
	float a, b, c;
	cin >> a >> b >> c;
	if (a + b > c || a + c > b || b + c > a)
	{
		if (a == b && b == c)
		{
			cout << "等边三角形" << endl;
		}
		else if (a == b || a == c || b == c)
		{
			cout << "等腰三角形" << endl;
		}
		else
		{
			cout << "一般三角形" << endl;
		}
	}
	else
	{
		cout << "这三条边不能构成三角形" << endl;
	}
}
int main()
{
	isTriangle();

	system("pause");
	return 0;
}

