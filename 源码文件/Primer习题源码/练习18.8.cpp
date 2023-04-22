/*
* 练习在析构函数中的try catch
*/
#include <iostream>
#include <string>
using namespace std;

class MyTest_Base
{
public:
	virtual ~MyTest_Base()
	{
		cout << "开始准备销毁一个MyTest_Base类型的对象" << endl;
		//把异常完全封装在析构函数内部
		try
		{
			//注意在析构函数中抛出了异常
			throw std::exception("在析构函数中故意抛出一个异常，测试！");
		}
		catch (const std::exception&)
		{
			//这里空实现
		}
	}
	void Func() throw()
	{
		throw std::exception("故意抛出一个异常，测试！");
	}

	void Other() {} //可能的其他函数
}; //重点是把可能发生异常的部分用try封装起来

int main()
{
	MyTest_Base myBase;
	//myBase.Func();

	system("pause");
	return 0;
}

