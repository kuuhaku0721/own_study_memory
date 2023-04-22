/*
* 定义你自己版本的hash<Sales_data>并定义一个Sales_data对象的unordered_multiset
* 将多条交易记录保存到容器中，并打印其内容。
*/
#include <iostream>
#include <string>
#include<cstddef>
#include<unordered_set>
#include<functional>
using namespace std;

//没有Sales_data类，先定义一个空的过一下编译
class Sales_data
{
public:

};

int main()
{
	//使用hash<Sales_data>和Sales_data的==运算符
	unordered_multiset<Sales_data> SDset;
	Sales_data item;
	while (cin >> item)
	{
		SDset.insert(item);
	}
	cout << SDset.size() << endl;
	for (auto sd : SDset)
		cout << sd << endl;

	system("pause");
	return 0;
}

