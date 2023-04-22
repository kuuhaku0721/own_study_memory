#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* reverse(begin, end);
* 反转指定范围内的元素
*/
void printVector(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "反转前：";
	printVector(v1);
	cout << "反转后：";
	reverse(v1.begin(), v1.end());
	printVector(v1);


}

int main()
{

	test01();



	system("pause");
	return 0;
}

