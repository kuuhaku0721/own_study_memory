#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* random_shuffle(begin, end);
* 指定范围内数据随机调整顺序
* 注意凡是随机的初始都是假随机，真随机要后来加随机数种子
* srand((unsigned int)time(NULL))    或许还要加<ctime>
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
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	cout << "排序后：";
	sort(v.begin(), v.end());
	printVector(v);
	cout << "打乱后：";
	random_shuffle(v.begin(), v.end());
	printVector(v);
	

}

int main()
{
	srand((unsigned int)time(NULL));
	test01();



	system("pause");
	return 0;
}

