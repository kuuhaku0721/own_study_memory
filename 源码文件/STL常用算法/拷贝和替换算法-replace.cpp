#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* replace(begin, end, oldValue, newValue);
* 将区间内旧元素替换为新元素
*/
void printVector(int val)
{
	cout << val << " ";
}
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

	replace(v1.begin(), v1.end(), 20, 666);

	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;

}
int main()
{

	test01();



	system("pause");
	return 0;
}
