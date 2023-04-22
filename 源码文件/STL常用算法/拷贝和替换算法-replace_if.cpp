#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* replace_if(begin, end, 谓词, newValue);
* 将区间内旧元素  按照谓词确定的条件 替换为新元素
*/
void printVector(int val)
{
	cout << val << " ";
}
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test01()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(40);
	v1.push_back(60);
	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;

	replace_if(v1.begin(), v1.end(), Greater20(), 999);

	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;

}
int main()
{

	test01();



	system("pause");
	return 0;
}
