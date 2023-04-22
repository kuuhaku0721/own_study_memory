/*
* 计算平均分
*/
#include <iostream>
#include <string>
using namespace std;
void avg()
{
	cout << "请确定科目数：";
	int n;
	cin >> n;
	cout << "请依次输入各科成绩：" << endl;
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		float num;
		cin >> num;
		sum += num;
	}
	cout << "平均分是：" << sum / n << endl;
}
int main()
{
	avg();

	system("pause");
	return 0;
}

