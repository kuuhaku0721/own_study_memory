/*
* 请编写函数 fun，该函数的功能是：移动一维数组中的内容，若数组中由 n 个整
* 数，要求把下标从 0 到 p(p 小于等于 n－1)的数组元素平移到数组的最后
*/
#include <iostream>
#include <string>
using namespace std;
void moveArr()
{
	//前提条件，假设数组全长20，默认填0，数据下标=10，移动小标<=9
	int arr[20] = { 0 };
	int n = 1;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = n++;
	}
	cout << "请输入要移动的下标：";
	int p;
	cin >> p;
	cout << "交换前：";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//交换
	for (int i = p, j = 19; i >= 0; i--, j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	cout << "交换后：";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	moveArr();

	system("pause");
	return 0;
}

