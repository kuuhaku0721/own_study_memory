/*
* 装饰模式
* 动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活
*/
#include <iostream>
#include <string>
using namespace std;

class Person  //相当于 ConcreteComponent 具体构建，因为就算写Component构建类也只有一个子类
{
public:
	Person()
	{
	}
	Person(string name)
	{
		this->name = name;
	}

	virtual void show()
	{
		cout << "装扮的是：" << name << endl;
	}

private:
	string name;
};

class Finery : public Person        //Decorator 装饰类 用来包装Person，下属可以有很多个ConcreteDecorator具体装饰类
{
public:
	void Decorate(Person* component)  //因为要判断是否空条件，所以要用指针，指针用处比较大，以后尽量多用指针吧
	{
		this->component = component;
	}

	void show()
	{
		if (component != NULL)
		{
			component->show();
		}
	}

protected:
	Person* component;
};

class TShirts : public Finery        //ConcreteDecorator具体装饰类,实现具体的功能
{
public:
	void show()
	{
		cout << "大T恤 ";
		Finery::show();
	}
};
class Pants : public Finery
{
public:
	void show()
	{
		cout << "垮裤 ";
		Finery::show();
	}
};
class Shoes : public Finery
{
public:
	void show()
	{
		cout << "耐克鞋 ";
		Finery::show();
	}
};                        //其余的ConcreteDecorator具体装饰类都类似的写法，可以接着扩展

int main()
{
	Person people("张三");
	cout << "第一种装扮：";

	TShirts* ts = NULL;
	Pants* pants = NULL;
	Shoes* shoes = NULL;

	ts->Decorate(&people);     //一层层套娃，一层层包装
	pants->Decorate(ts);
	shoes->Decorate(pants);
	shoes->show();

	system("pause");
	return 0;
}

