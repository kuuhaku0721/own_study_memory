/*
* 输入 n 个成绩，换行输出 n 个成绩中最高分数和最低分数的差。
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
void maxMin()
{
	cout << "请输入个数n：";
	int n;
	cin >> n;
	vector<int> v;  //或者用multiset
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << "最高分与最低分之差为：" << *(v.end() - 1) - *v.begin() << endl;
}
int main()
{
	maxMin();

	system("pause");
	return 0;
}

