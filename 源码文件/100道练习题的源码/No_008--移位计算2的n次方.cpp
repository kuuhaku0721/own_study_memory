/*
* 不适用累加，通过移位<<计算2的n次方
*/
/*存在的问题同003，分行输入*/
#include <iostream>
#include <string>
using namespace std;
void moveN(int n)
{
	int a = 1;
	for (int i = 0; i < n; i++)
	{
		a = a << 1;
	}
	cout << a << endl;
	
}
int main()
{
	cout << "请输入n的值：";
	int n;
	cin >> n;
	moveN(n);
	//能多次输入但是依旧存在问题，scanf c可以用c++没有不能用就没法实现，但是如果用cin.get() 会导致程序无法退出
	//经测试，这样写在c里面依然无法退出
	/*int a = 1, n;
	while (cin.get() != EOF) {
		cin >> n;
		a <<= n;
		printf("%d\n", a);
	}*/

	system("pause");
	return 0;
}

