/*
* 状态模式
* 目的是消除了庞大的条件分支语句，将条件分支的内容全部独立出一个类来相互实例化调用
* 使用时机：当一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为时，就可以考虑使用状态模式
*/
#include <iostream>
#include <string>
using namespace std;

class Work
{
public:
	Work()
	{
		current = new ForenoonState();
	}

	double getHour()
	{
		return this->Hour;
	}
	void setHour(double value)
	{
		this->Hour = value;
	}
	bool getFinish()
	{
		return this->finish;
	}
	void setFinish(bool value)
	{
		this->finish = value;
	}
	void SetState(State* s)
	{
		current = s;
	}
	void WriteProgram()
	{
		current->WriteProgram(*this);
	}

private:
	State* current;
	double Hour;
	bool finish = false;
};
//状态类
class State
{
public:  //状态抽象类--不写抽象了，抽象类没法实例化对象
	void WriteProgram(Work w) {} //写代码的虚函数
};
//上午工作状态
class ForenoonState : public State
{
public:
	void WriteProgram(Work w)
	{
		if (w.getHour() < 12)
		{
			cout << "当前时间：" << w.getHour() << "点，上午工作，精神百倍" << endl;
		}
		else
		{
			w.SetState(new NoonState());
			w.WriteProgram();
		}
	}
};
//中午工作状态
class NoonState : public State
{
public:
	void WriteProgram(Work w)
	{
		if (w.getHour() < 13)
		{
			cout << "当前时间：" << w.getHour() << "点，饿了，午饭，犯困，睡觉" << endl;
		}
		else
		{
			w.SetState(new AfternoonState());
			w.WriteProgram();
		}
	}
};
//下午和傍晚工作状态
class AfternoonState : public State
{
public:
	void WriteProgram(Work w)
	{
		if (w.getHour() < 17)
		{
			cout << "当前时间：" << w.getHour() << "点，下午状态还不错，继续努力" << endl;
		}
		else
		{
			//w.SetState(new EveningState());
			w.WriteProgram();
		}
	}
};



int main()
{
	Work emergencyProjects;
	emergencyProjects.setHour(9);
	emergencyProjects.WriteProgram();
	emergencyProjects.setHour(10);
	emergencyProjects.WriteProgram();
	emergencyProjects.setHour(12);
	emergencyProjects.WriteProgram();
	emergencyProjects.setHour(14);
	emergencyProjects.WriteProgram();

	system("pause");
	return 0;
}

