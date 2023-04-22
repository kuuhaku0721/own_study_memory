#include <iostream>
#include <string>
using namespace std;

class LeiFeng
{
public:
	void Sweep()
	{
		cout << "扫地" << endl;
	}
	void Wash()
	{
		cout << "洗衣服" << endl;
	}
	void Buy()
	{
		cout << "买东西" << endl;
	}
};
//学雷锋的大学生
class UnderGraduate : public LeiFeng
{
public:
	//这里可以添加别的东西
};
//社区志愿者
class Volunteer : public LeiFeng
{
public:
	//这里可以添加别的东西
};

/*
* 工厂方法模式，与简单工厂模式不同的是，简单工厂模式是通过一个工厂类，来通过不同的选择实例化不同的对象
* 较多的利用了多态的特性
* 而工厂方法模式，会发现它多了很多个工厂，不在单单只有一个工厂类来统一管理，好处在下面
*/

//雷锋工厂
class IFactory
{ //抽象类（有虚函数即成为抽象类）
public:
	virtual LeiFeng createLeiFeng() = 0; //类似java的接口，虚函数，后面跟着=0，可以只写声明不写定义
};
//学雷锋的发学生工厂
class UndergraduateFactory : public IFactory
{
public:
	LeiFeng createLeiFeng()
	{
		UnderGraduate stu;
		return stu;
	}
};
//社区志愿者工厂
class VolunteerFactory : public IFactory
{
public:
	LeiFeng createLeiFeng()
	{
		Volunteer vol;
		return vol;
	}
};

int main()
{
	IFactory* factory = new UndergraduateFactory();  //父类指针指向子类对象，用雷锋工厂创建学生工厂
			//意志会传递，如果需要改变干活的人，只需要将这里的学生工厂换成志愿者工厂，其他的都不需要改变

	LeiFeng student1 = factory->createLeiFeng(); //最终目的是创建雷锋，雷锋的行为会一直留存，但是在不同的人之间传递，如果是简单工厂模式
	//如果换人了，不再是学生而是社区志愿者，那么不仅仅父类指针的指向需要改变，工厂内每一步都要改变对象（在下面调用方法的地方，改变的那里的对象）

	student1.Sweep();  //如果干活的对象变了，这里也不用更改，只需要更改一处即可，这就是工厂方法模式的优点
	student1.Wash();
	student1.Buy();

	system("pause");
	return 0;
}

