/*代理模式，代理类替主类去实现接口方法类,所以还是套娃*/
#include <iostream>
#include <string>
using namespace std;
/*
* 代理模式
* 在主与客之间插入一个代理，让代理去代替主实现主的方法导向客
* 
*/
//接口方法
class IGiveGift
{
	void GiveDolls();
	void GiveFlowers();
	void GiveChocolate();
};
//目标对象类
class SchoolGirl
{
public:
	//可以添加其他属性

	string name;
};

class Pursuit : public IGiveGift
{
public:
	Pursuit(SchoolGirl mm)
	{
		this->mm = mm;
	}

	void GiveDolls()
	{
		cout << "给妹子：" << mm.name << " 送玩偶~~~" << endl;
	}

	void GiveFlowers()
	{
		cout << "给妹子：" << mm.name << " 送fafa~~~" << endl;
	}

	void GiveChocolate()
	{
		cout << "给妹子：" << mm.name << " 送巧克力~~~" << endl;
	}
private:
	SchoolGirl mm;
};
//代理类
class Proxy : public IGiveGift
{
public:
	Proxy(SchoolGirl mm)
	{
		this->gg = new Pursuit(mm);
	}

	void GiveDolls()
	{
		gg->GiveDolls();
	}

	void GiveFlowers()
	{
		gg->GiveFlowers();
	}

	void GiveChocolate()
	{
		gg->GiveChocolate();
	}

private:
	Pursuit* gg;
};



int main()
{
	SchoolGirl mm;
	mm.name = "小可爱";

	Proxy daili(mm);

	daili.GiveDolls();
	daili.GiveFlowers();
	daili.GiveChocolate();

	system("pause");
	return 0;
}

