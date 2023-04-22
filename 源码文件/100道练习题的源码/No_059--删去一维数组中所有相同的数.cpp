/*
* 删去一维数组中所有相同的数，使之只剩一
* 个。数组中的数已按由小到大的顺序排列，函数返回删除后数组中数据的个数
*/
#include <iostream>
#include <string>
#include<set>
using namespace std;
void deleteSame(int arr[], int n)
{
	cout << "结果：" << endl;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(arr[i]);
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "个数为：" << s.size() << endl;
}
int main()
{
	int arr[15] = { 1,2,2,3,3,3,4,4,5,6,7, 8, 8, 8,9 };
	deleteSame(arr, 15);

	system("pause");
	return 0;
}

