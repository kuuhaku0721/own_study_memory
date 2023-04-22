#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
* count_if(begin, end, 谓词);
* 按条件(谓词)统计元素出现的次数
*/
class Greater3
{
public:
	bool operator()(int val)
	{
		if (val > 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//统计个数
	int num = count_if(v.begin(), v.end(), Greater3());
	cout << "大于3的个数为：" << num << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
class Greater20
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_age > 20)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//统计自定义数据类型 
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
	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "年龄大于20的个数有：" << num << endl;
}
int main()
{

	test01();
	test02();



	system("pause");
	return 0;
}

