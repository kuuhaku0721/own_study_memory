/*
* 编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()成员
* 使用这个函数排序一个保存Sales_data对象的vector
*/
/*
* 将compareIsbn定义为一个二元谓词，接受两个Sales_data对象
* 通过isbn成员函数获取ISBN编号，若前者小于后者返回真，否则返回假
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

class Sales_data
{
public:
	string isbn()
	{
		return this->ISBN;
	}
	string ISBN;
};

inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.ISBN < rhs.ISBN;
}

int main()
{
	vector<Sales_data> sds;
	Sales_data sd1;
	sd1.ISBN = "12345001";
	Sales_data sd2;
	sd2.ISBN = "43226002";
	Sales_data sd3;
	sd3.ISBN = "89760003";
	Sales_data sd4;
	sd4.ISBN = "23029004";
	Sales_data sd5;
	sd5.ISBN = "12875005";
	sds.push_back(sd1);
	sds.push_back(sd2);
	sds.push_back(sd3);
	sds.push_back(sd4);
	sds.push_back(sd5);
//                                二元谓词
	sort(sds.begin(), sds.end(), compareIsbn);
	
	for (const auto& s : sds)
	{
		cout << s.ISBN << endl;
	}

	system("pause");
	return 0;
}

