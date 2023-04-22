/*
* 组合模式
* 将对象组合成树形结构以表示‘部分-整体’的层次结构。
* 组合模式使得用户对单个对象和组合对象的使用具有一致性
* 当需求中是体现部分与整体层次的结构时，或者希望用户可以忽略组合对象与单个对象的不同，统一地使用组合结构中的所有对象时考虑使用组合模式
*/
#include <iostream>
#include <string>
#include<list>
using namespace std;

class Company
{
public:
	Company(string name)
	{
		this->name = name;
	}
	//接口
	void Add(Company c); //增加
	void Remove(Company c); //移除
	void Display(int depth); //显示
	void LineOfDuty(); //履行职责
protected:
	string name;
};
//具体公司类，树枝结点，实现接口
class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string name) : Company(name) //用这个方法去调用父类构造，相当于super
	{
	}
	void Add(Company c)
	{
		children.push_back(c);
	}
	void Remove()
	{
		children.pop_back();
	}
	void Display(int depth)
	{
		for (list<Company>::iterator it = children.begin(); it != children.end(); it++)
		{
			(*it).Display(depth++);
		}
	}
	//履行职责
	void LineOfDuty()
	{
		for (list<Company>::iterator it = children.begin(); it != children.end(); it++)
		{
			(*it).LineOfDuty();
		}
	}
private:
	list<Company> children;
};
//人力资源部
class HRDepartment : public Company
{
public:
	HRDepartment(string name) : Company(name)
	{
	}
	void Add(Company c)
	{
	}
	void Remove(Company c)
	{
	}
	void Display(int depth)
	{
		cout << depth << "--" << name << endl;
	}
	void LineOfDuty()
	{
		cout << name << " " << "员工招聘培训管理" << endl;
	}
};
//财务部
class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string name) : Company(name)
	{
	}
	void Add(Company c)
	{
	}
	void Remove(Company c)
	{
	}
	void Display(int depth)
	{
		cout << depth << "--" << name << endl;
	}
	void LineOfDuty()
	{
		cout << name << " " << "公司财务收支管理" << endl;
	}
};

int main()
{
	ConcreteCompany root("北京总公司");
	HRDepartment hr("总公司人力资源部");
	root.Add(hr);
	FinanceDepartment fin("总公司财务部");
	root.Add(fin);

	ConcreteCompany comp1("上海华东分公司");
	HRDepartment hr1("华东分公司人力资源部");
	comp1.Add(hr1);
	FinanceDepartment fin1("华东分公司财务部");
	comp1.Add(fin1);

	ConcreteCompany comp2("南京办事处");
	HRDepartment hr2("南京办事处人力资源部");
	comp2.Add(hr2);
	FinanceDepartment fin2("南京办事处财务部");
	comp2.Add(fin2);

	ConcreteCompany comp3("杭州办事处");
	HRDepartment hr3("杭州办事处人力资源部");
	comp3.Add(hr3);
	FinanceDepartment fin3("杭州办事处财务部");
	comp3.Add(fin3);

	cout << "结构图？？" << endl;
	root.Display(1);

	cout << "\n职责：" << endl;
	root.LineOfDuty();

	system("pause");
	return 0;
}

