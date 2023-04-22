/*
* 利用<algorithm>库的fill_n（begin, size, value）算法将容器内的int值都设置为0
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10 };
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;

	fill_n(v.begin(), v.size(), 0);

	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

