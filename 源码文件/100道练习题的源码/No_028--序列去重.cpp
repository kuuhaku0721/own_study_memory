/*
* 输入 n 个整数的序列，要求对这个序列进行去重操作。所谓去重，是指对这个序列中每个重复出现的整数，
* 只保留该数第一次出现的位置，删除其余位置。
* 两行输入，第一行个数，第二行序列
*/
#include <iostream>
#include <string>
#include<set>
using namespace std;
void removeRepeat()
{
	cout << "请输入序列的个数：";
	int n;
	cin >> n;
	//题目原本意思可能是用循环嵌套来判断是否已经存在决定是否插入，时间复杂度会比较大
	//但是既然有现成的容器何不用呢
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num); //如果重复将插入失败
	}
	cout << "最终结果为：" << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	removeRepeat();

	system("pause");
	return 0;
}

