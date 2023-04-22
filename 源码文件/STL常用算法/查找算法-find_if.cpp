#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
* find_if(begin, end, 谓词);
* 查找指定元素，找到返回迭代器 没有返回end()
*/
class Greater
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找                                     放函数对象 类名+()s
	vector<int>::iterator pos = find_if(v.begin(), v.end(), Greater());
	if (pos != v.end())
	{
		cout << "找到了并且=" << *pos << endl;
	}
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
	bool operator()(Person& p)
	{
		return p.m_age > 20;
	}
};
//查找自定义数据类型  要重载==
void test02()
{
	vector<Person> v;
	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
	if (pos != v.end())
	{
		cout << "存在并且”：" << endl;
		cout << (*pos).m_name << " + " << (*pos).m_age << endl;
	}
}
int main()
{

	test01();
	test02();



	system("pause");
	return 0;
}

