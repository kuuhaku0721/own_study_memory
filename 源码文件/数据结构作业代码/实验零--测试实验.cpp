/*
* 1）多个数的求和、平均、最大值、最小值
* 输入：1、3、5、10、16、-1
* 输出：总和 = 35；平均值 = 7； 最大值 = 16； 最小值 = 1
* 2）集合的交、并差
* 输入： A={1,2,3,4,5}        B={3,4,5,6,7}
* 输出 A交B={3， 4， 5}  A并B={1，2，3，4，5，6，7}  A-B={1, 2}
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
void test01() 
{
	//求和，平均，最大，最小
	cout << "请输入数据，以负数结尾：" << endl;
	vector<int> v;
	while (true)
	{
		int n;
		cin >> n;
		if (n < 0)
		{
			break;
		}
		v.push_back(n);
	}
	int sum = 0;
	int max = v[0];
	int min = v[0];
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		sum += *it;
		if (max <= *it)
		{
			max = *it;
		}
		if (min >= *it)
		{
			min = *it;
		}
	}
	cout << "总和为：" << sum << endl;
	cout << "平均为：" << sum / v.size() << endl;
	cout << "最大为：" << max << endl;
	cout << "最小为：" << min << endl;
}

void JBC(vector<int>& v1, vector<int>& v2)
{
	vector<int> vUnion; //并
	vector<int> vIntersection;//交
	vector<int> vDifference; //差
	vUnion = v1;
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		if (find(vUnion.begin(), vUnion.end(), *it) == vUnion.end())
		{
			//查找v1 = v1.end 说明不存在此元素
			vUnion.push_back(*it);
		}
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		for (vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); it2++)
		{
			if (*it == *it2 && find(vIntersection.begin(), vIntersection.end(), *it) == vIntersection.end())
			{
				vIntersection.push_back(*it);
			}
		}
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		if (find(vIntersection.begin(), vIntersection.end(), *it) == vIntersection.end())
		{
			vDifference.push_back(*it);
		}
	}
	cout << "并集为：";
	for (vector<int>::iterator it = vUnion.begin(); it != vUnion.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "交集为：";
	for (vector<int>::iterator it = vIntersection.begin(); it != vIntersection.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "差集为：";
	for (vector<int>::iterator it = vDifference.begin(); it != vDifference.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void gatherSimple()
{
	vector<int> v1;
	for (int i = 1; i <= 5; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 3; i <= 7; i++)
	{
		v2.push_back(i);
	}

	//直接调用
	JBC(v1, v2);

}
void gatherPersonal()
{
	cout << "请确定集合A的大小：";
	int m;
	cin >> m;
	vector<int> v1;
	cout << "请依次输入集合A的数据：" << endl;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		v1.push_back(num);
	}
	cout << "请确定集合B的大小：";
	int n;
	cin >> n;
	vector<int> v2;
	cout << "请依次输入集合B的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v2.push_back(num);
	}

	//直接调用
	JBC(v1, v2);

}

void test02()
{
	cout << "请选择：" << endl;
	cout << "1----使用默认值" << endl;
	cout << "2----自己输入值" << endl;
	cout << "     其余任意键退出" << endl;
	while (1)
	{
		cout << "----请输入----" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			gatherSimple();
			break;
		case 2:
			gatherPersonal();
			break;
		default:
			cout << "程序已退出" << endl;
			return;
		}
	}
}

int main()
{
	cout << "请输入想要启动的测试案例：" << endl;
	cout << "1--------求和，平均，最值" << endl;
	cout << "2--------集合的交并差" << endl;
	int command;
	cin >> command;
	switch (command)
	{
	case 1:
		test01();
		break;
	case 2:
		test02();
		break;
	default:
		cout << "输入有误，请重新输入" << endl;
		break;
	}

	system("pause");
	return 0;
}

