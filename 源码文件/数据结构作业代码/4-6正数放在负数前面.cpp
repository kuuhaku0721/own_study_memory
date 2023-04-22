/*
* n个数字存放在数组中，将所有正数排在负数前面
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void sort_max_min()
{
	int arr[10] = { -1, -2,3,-4,5,-6,7,-8,9,10 };
	int len = 10;
	cout << "转移前：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//从头到尾遍历，如果是负数就入栈不出，如果是正数就从第一个开始放,最后将栈中所有元素从数组最后一个正数开始放入数组
	stack<int> s;
	int i = 0;
	int index = 0;
	while (i < len)
	{
		if (arr[i] < 0)
		{
			s.push(arr[i]);
		}
		if (arr[i] >= 0)
		{
			arr[index] = arr[i];
			index++;
		}
		i++;
	}
	for (int i = index; i < len; i++)
	{
		arr[i] = s.top();
		s.pop();
	}

	cout << "转移后：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	sort_max_min();

	system("pause");
	return 0;
}