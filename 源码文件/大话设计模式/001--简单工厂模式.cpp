/*
* 利用工厂模式实现一个计算器的加减乘除运算
* 将底层数据私有化，提供对外接口，封装基类
* 子类提供同一基类下不同的实例方法
* 提供工厂类来管理具体实例化哪个方法
*/
#include <iostream>
#include <string>
using namespace std;
#define ADD 0
#define SUB -1
#define MUL 2
#define DIV 1

class Operation
{
public:
	double get_numberA()  //设立数据的get和set接口  可以分出去好几个类写也可以分出去头文件来写
	{
		return this->numberA;
	}
	void set_numberA(int value)
	{
		this->numberA = value;
	}

	double get_numberB()
	{
		return this->numberB;
	}
	void set_numberB(int value)
	{
		this->numberB = value;
	}

	virtual double GetResult()                                                              //封装
	{
		double result = 0.0;
		return result;
	}
private:    //私有化自身数据，保护数据，设立接口访问
	double numberA;
	double numberB;
};

/*四个具体实现的子类，都继承父类，保证都要重写得到结果的函数，并且要使用父类的私有数据*/     //继承
/*好处在于如果以后想要增加一种运算可以直接在后面添加，同时继承父类就能拿到数据*/
class OperationAdd : public Operation
{
	double GetResult()
	{
		double result = 0.0;
		result = get_numberA() + get_numberB();
		return result;
	}
};

class OperationSub : public Operation
{
	double GetResult()
	{
		double result = 0.0;
		result = get_numberA() - get_numberB();
		return result;
	}
};

class OperationMul : public Operation
{
	double GetResult()
	{
		double result = 0.0;
		result = get_numberA() * get_numberB();
		return result;
	}
};

class OperationDiv : public Operation
{
	double GetResult()
	{
		double result = 0.0;
		if (get_numberB() == 0)
		{
			cout << "除数不能为0" << endl;
			return -1;
		}
		result = get_numberA() / get_numberB();
		return result;
	}
};

class OperationFactory    //设立工厂来控制实例化不同的对象                                   //多态
{
public:
	Operation* oper = NULL;
	Operation* createOperate(int operate)  //这里switch不能用字符串类型，字符串类型不是枚举类型，所以换做宏定义的常数
	{
		switch (operate)  //C++的多态时用子类对象调用父类函数，没有父类对象指向子类对象
		{
		case ADD:
			oper = new OperationAdd;   //注意C++中如果想父类成员指向子类对象要用指针的形式，或者父类指针指向子类成员的引用
			break;
		case SUB:
			oper = new OperationSub;  //通过不同的选择实例化不同的子类，利用多态的特性统一管理，最终返回父类，利用父类指针指向子类对象
			break;
		case MUL:
			oper = new OperationMul;
			break;
		case DIV:
			oper = new OperationDiv;
			break;
		default:
			cout << "输入错误" << endl;
		}
		return oper;
	}
};

int main()
{
	Operation *oper;  //定义父类指针
	OperationFactory of;
	oper = of.createOperate(ADD);  //通过函数返回使父类指针指向子类对象

	oper->set_numberA(1);  //此时父类已经指向了加法子类，直接通过父类接口定义数据
	oper->set_numberB(2);
	double result = oper->GetResult();  //通过父类的函数得到结果
	cout << result << endl;

	system("pause");
	return 0;
}

