#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* swap(容器1， 容器2);
* 互换两个容器的元素
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

	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
	}
	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;
	for_each(v2.begin(), v2.end(), printVector);
	cout << endl;

	swap(v1, v2);
	cout << "交换后：" << endl;
	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;
	for_each(v2.begin(), v2.end(), printVector);
	cout << endl;

}
int main()
{

	test01();



	system("pause");
	return 0;
}
