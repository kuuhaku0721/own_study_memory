/*
* 外观模式
* 为子系统的一组接口提供一个一致的界面，即定义一个高层接口，使得子系统更加容易使用
* 比如一个应用场景，现在有ABCD四个类分别实现四个不同的方法或不同对象，客户端需要多次调用ABCD中不同的组合
* 比如一次调用AC，又调用一次CDA等等，如果每次都重复调用代码会很复杂冗长，因此提供一个Facade类来实现不同的组合
* 客户端不需要了解ABCD每一个，只需要知道Facade一个接口即可，通过调用Facade不同的方法来实现不同组合的调用
*/
#include <iostream>
#include <string>
using namespace std;

class SystemOne
{
public:
	void MethodOne()
	{
		cout << "子系统方法一" << endl;
	}
};
class SystemTwo
{
public:
	void MethodTwo()
	{
		cout << "子系统方法二" << endl;
	}
};
class SystemThree
{
public:
	void MethodThree()
	{
		cout << "子系统方法三" << endl;
	}
};
class SystemFour
{
public:
	void MethodFour()
	{
		cout << "子系统方法四" << endl;
	}
};
class Facade
{
public:
	Facade()
	{
		one = new SystemOne;
		two = new SystemTwo;
		three = new SystemThree;
		four = new SystemFour;
	}

	void methodA()
	{
		cout << "方法组合A" << endl;
		one->MethodOne();
		three->MethodThree();
		four->MethodFour();
	}

	void methodeB()
	{
		cout << "方法组合B" << endl;
		three->MethodThree();
		two->MethodTwo();
	}

private:
	SystemOne* one;
	SystemTwo* two;
	SystemThree* three;
	SystemFour* four;
};
int main()
{
	//客户端现在想要调用不同的组合就不需要定义不同的对象然后去实现它们各自的方法了
	//只需要声明一个门面Facade对象，通过门面Facade对象来调用不同的组合
	Facade face;

	face.methodA();
	face.methodeB();

	system("pause");
	return 0;
}

