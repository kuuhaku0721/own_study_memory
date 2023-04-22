/*
* 备忘录模式
* 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
* 适用于功能比较复杂，但是需要维护或记录属性历史的类，或者需要保存的属性只是众多属性中的一小部分时
* so,备份模式？
*/
#include <iostream>
#include <string>
using namespace std;

class RoleStateMemento
{ //角色状态备忘录
public:
	RoleStateMemento()
	{

	}
	RoleStateMemento(int vit, int atk, int def)
	{
		this->vit = vit;
		this->atk = atk;
		this->def = def;
	}
	//生命力
	int get_Vitality()
	{
		return vit;
	}
	void set_Vialiity(int vit)
	{
		this->vit = vit;
	}
	//攻击力
	int get_Attack()
	{
		return atk;
	}
	void set_Attack(int atk)
	{
		this->atk = atk;
	}
	//防御力
	int get_Defense()
	{
		return def;
	}
	void set_Defense(int def)
	{
		this->def = def;
	}
private:
	int vit; //生命
	int atk; //攻击
	int def; //防御
};
class GameRole
{
public:
	//生命力
	int get_Vitality()
	{
		return vit;
	}
	void set_Vialiity(int vit)
	{
		this->vit = vit;
	}
	//攻击力
	int get_Attack()
	{
		return atk;
	}
	void set_Attack(int atk)
	{
		this->atk = atk;
	}
	//防御力
	int get_Defense()
	{
		return def;
	}
	void set_Defense(int def)
	{
		this->def = def;
	}

	//保存角色状态
	RoleStateMemento SaveState()
	{
		RoleStateMemento tempRole(vit, atk, def);
		return tempRole;
	}
	//恢复角色状态
	void RecoveryState(RoleStateMemento memento)
	{
		this->vit = memento.get_Vitality();
		this->atk = memento.get_Attack();
		this->def = memento.get_Defense();
	}
	//状态显示
	void StateDisplay()
	{
		cout << "角色当前状态：" << endl;
		cout << "体力：" << this->vit << endl;
		cout << "攻击力：" << this->atk << endl;
		cout << "防御力：" << this->def << endl;
	}
	//获得初始状态
	void GetInitState()
	{
		this->vit = 100;
		this->atk = 100;
		this->def = 100;
	}
	//战斗，直接清零
	void Fight()
	{
		this->vit = 0;
		this->atk = 0;
		this->def = 0;
	}
private:
	int vit;
	int atk;
	int def;
};
//角色状态管理者
class RoleStateCaretaker
{
public:
	RoleStateCaretaker()
	{
	}
	RoleStateMemento get_Memento()
	{
		return this->memento;
	}
	void set_Memento(RoleStateMemento memento)
	{
		this->memento = memento;
	}
private:
	RoleStateMemento memento;
};

int main()
{
	//大战BOSS前
	GameRole zhangsan;
	zhangsan.GetInitState(); //初始化三项数据
	zhangsan.StateDisplay();

	//保存进度
	RoleStateCaretaker stateAdmin;
	stateAdmin.set_Memento(zhangsan.SaveState());

	//大战BOSS，全扑街了
	zhangsan.Fight();
	zhangsan.StateDisplay();

	//回档，状态恢复之前的            ---        这里就是备忘录模式的应用，就是存档备份,然后读档
	zhangsan.RecoveryState(stateAdmin.get_Memento());
	zhangsan.StateDisplay();

	system("pause");
	return 0;
}

