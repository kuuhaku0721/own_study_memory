#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
* count(begin, end, value);
* 统计元素出现的次数
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	//统计个数
	int num = count(v.begin(), v.end(), 2);
	cout << "个数为：" << num << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//重载==让count知道如何对比  注意要加const
	bool operator==(const Person& p)
	{
		if (this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};
//查找自定义数据类型  要重载==
void test02()
{
	vector<Person> v;
	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	Person p5("周七", 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person pp("测试人", 20);
	int num = count(v.begin(), v.end(), pp);
	cout << "年龄相同的个数有：" << num << endl;
}
int main()
{

	test01();
	test02();



	system("pause");
	return 0;
}

