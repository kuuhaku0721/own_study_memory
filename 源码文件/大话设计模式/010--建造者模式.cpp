/*
* 建造者模式
* 其实还是用接口来限制子类的操作，让子类必须实现某些操作
* 不同的是将建造的过程与客户端分类，单独用一个Director指挥者类来衔接上下两部分
* 客户端告诉Director指挥者我需要建造一个什么样的对象，指挥者拿到要求之后去建造类构建该对象
* 适用于建造过程比较庞大复杂的情形下，有点是摆脱了建造过程和用户之间的耦合
*/
#include <iostream>
#include <string>
using namespace std;
class Builder
{
public:
	virtual void head() = 0;
	virtual void body() = 0;
	virtual void arms() = 0;
	virtual void legs() = 0;
};
class ConcreteBuildA : public Builder
{
public:
	void head()
	{
		cout << "小头" << endl;
	}
	void body()
	{
		cout << "大身体" << endl;
	}
	void arms()
	{
		cout << "小胳膊" << endl;
	}
	void legs()
	{
		cout << "小腿" << endl;
	}
};
class ConcreteBuildB : public Builder
{
public:
	void head()
	{
		cout << "大头" << endl;
	}
	void body()
	{
		cout << "小身体" << endl;
	}
	void arms()
	{
		cout << "大胳膊" << endl;
	}
	void legs()
	{
		cout << "大腿" << endl;
	}
};
class Director
{
	//指挥者类，用来指挥建造过程
public:
	void Construct(Builder* builder)
	{
		builder->head();
		builder->body();
		builder->arms();
		builder->legs();
	}
};
int main()
{
	Director director;
	Builder* b1 = new ConcreteBuildA;
	Builder* b2 = new ConcreteBuildB;

	cout << "指挥构建A" << endl;
	director.Construct(b1);

	cout << endl << "指挥构建B" << endl;
	director.Construct(b2);

	system("pause");
	return 0;
}

