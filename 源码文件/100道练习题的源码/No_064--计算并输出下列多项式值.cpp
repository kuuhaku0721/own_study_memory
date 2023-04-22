/*
*	请编写函数 fun，其功能是：计算并输出下列多项式值:sn=(1-1/2)+(1/3-1/4)+…+(1/(2n-1)1/2n).
*/
#include <iostream>
#include <string>
using namespace std;
void calcalator()
{
	cout << "请输入目标位置n：";
	int n;
	cin >> n;
	bool flag = false;
	double sum = 0.0;
	for (int i = 1; i < n; i=i+2)
	{
		sum += (1.0 / i) - 1.0 / (i + 1);
	}
	cout << "结果为：" << sum << endl;
}
int main()
{
	calcalator();

	system("pause");
	return 0;
}

