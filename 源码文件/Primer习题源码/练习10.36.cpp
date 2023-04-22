/*
* 使用find在一个int的list中查找最后一个值为0的元素
*/
#include <iostream>
#include <string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	list<int> li = { 0,1,2,0,3,4,5,0,6 };
	//利用反向迭代器查找最后一个0
	auto last_zero = find(li.rbegin(), li.rend(), 0);
	//将迭代器向链表头推进一个位置
	//转换为普通迭代器时，将回到最后一个0的位置
	last_zero++;
	int p = 1;
	//用base将last_zero转换为普通迭代器
	//从链表头开始遍历，计数最后一个0的编号
	for (auto iter = li.begin(); iter != last_zero.base(); iter++, p++)
	{ }

	if (p >= li.size())
	{
		//没有找到0
		cout << "容器中没有0" << endl;
	}
	else
	{
		cout << "最后一个0在第：" << p << "个位置" << endl;
	}

	system("pause");
	return 0;
}

