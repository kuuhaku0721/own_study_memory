
/*
* 写在整个练习之前
* 这个项目是用来写C++Primer习题集第五版的练习题的
* 练习题内容从第九章开始
* 一写简答题和必要性不高的习题不再添加，因此源文件命名会出现不连续的情况
* 因为只是练习，一般都集中在一个cpp文件当中，故不再区分头文件和源文件之分
*/

/*
* 定义一个list对象，其元素类型是int的deque
*/
#include <iostream>
#include <string>
#include<deque>
#include<list>
using namespace std;

class Solution
{
public:
	void buildAList()
	{
		list<deque<int>> L;
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

