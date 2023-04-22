/*
* 策略模式是一种定义一系列算法的方法，从概念上看，所有这些算法完成的都是相同的工作，只是实现不同，它可以以相同的方式调用所有算法
* 减少了各种算法类与使用算法类之间的耦合
* 只要分析时发现，需要在不同时间应用不同的业务规则，就可以考虑使用策略模式处理这种变化的可能性
* 主要是，改动小，修改维护成本低
*/
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
#define NORMAL 0
#define RETURN 1
#define REBATE 2

class CashSuper      //抽象类只当作父类，要么只定义方法接口，要么指向子类对象
{
public:
	virtual double acceptCash(double money) = 0; //含有纯虚函数的类被称为抽象类。抽象类只能作为派生类的基类，不能定义对象，但可以定义指针。
		                                     //在派生类实现该纯虚函数后，定义抽象类对象的指针，并指向或引用子类对象。
};
                                             //继承
class CashNormal : public CashSuper
{
public:
	virtual double acceptCash(double money)
	{
		return money;
	}
};

class CashRebate : public CashSuper
{
public:
	CashRebate(double moneyRebate)  //C++并没用那么方便的直接把string转换成double的API，所以这里暂时先直接用double
	{
		this->moneyRebate = moneyRebate;
	}

	double acceptCash(double money)
	{
		return money * this->moneyRebate;
	}

private:
	double moneyRebate = 1.0;
};
                                             //封装
class CashReturn : public CashSuper
{
public:
	CashReturn(double moneyCondition, double moneyReturn)
	{
		this->moneyCondition = moneyCondition;
		this->moneyReturn = moneyReturn;
	}

	double acceptCash(double money)         //返利消费，比如满300返100
	{
		double result = money;
		if (money >= moneyCondition)
		{                   //<math.h>
			result = money - floor(money / moneyCondition) * moneyReturn;         //大于返利条件，减去返利值
		}
		return result;
	}

private:
	double moneyCondition = 0.0;
	double moneyReturn = 0.0;
};

/*策略模式与工厂模式结合*/
class CashContext                  //该方法使得客户端与底层耦合度更低，客户只需要认得CashContext这一个函数即可
{                              //在客户端实例化的时CashContext对象，调用的也是CashContext的函数，这使得具体的收费算法与客户端分离
public:                        //其实真正分类应该是分文件编写，这样才是真正做到完全分离开，客户端只需要看到一个CashContext.cpp文件即可
	CashSuper *cs;             //这样的策略模式优化了单元测试，因为每个算法都有自己的类，可以通过自己的接口测试
	CashContext(int type)
	{
		switch (type)
		{
		case NORMAL:
			cs = new CashNormal(); //正常                             //多态
			break;
		case RETURN:
			cs = new CashReturn(300, 100); //满减
			break;
		case REBATE:
			cs = new CashRebate(0.8); //打折
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
	}

	double getResult(double money)
	{
		return cs->acceptCash(money);
	}
};

int main()
{
	double total = 0.0;          //指针对象不能用构造函数初始化，正常实例化才能有构造函数初始
	CashContext csuper(REBATE);  //通过窗体下拉框选择优惠力度
	double money = 300;          //钱数也由窗体获得，这里直接定义默认值
	int num = 1;        //数量也由窗体获得，这里默认1个
	double totalPrices = csuper.getResult(money) * num;
	total += totalPrices;
	cout << "最终金额：" << total << endl;  //如果需要其他信息输出，只需要在窗体输入的时候多拿到几个数据即可

	system("pause");
	return 0;
}


/*
* 策略模式与工厂模式的区别（虽然策略模式在Context中是策略模式与工厂模式结合的方式）
* 工厂模式是通过多态去实例化不同的对象，最终目的是通过不同的对象实现不同对象的不同方法
* 策略模式是也是实例化不同对象，但是实例化是使用对象的某个或某部分方法，而且所有对象方法相同，只是实现不同：比如加减乘除，方法相同只是实现不同
* 总之就是，工厂模式注重对象成员，策略模式注重成员方法
*/

