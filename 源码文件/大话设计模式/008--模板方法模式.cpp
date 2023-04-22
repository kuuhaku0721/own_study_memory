#include <iostream>
#include <string>
using namespace std;
/*
* 模板方法模式
* 定义一个操作中的算法股价，将一些步骤延迟到子类中，这样可以不改变一个算法的结构即可重定义该算法的某些特定步骤
* 模板方法一般是一个具体的方法，与其他模式不同的是，其他模式多用接口实现多态（接口，只声明，不定义），模板方法模式提供了具体的方法实现
* 这样可以去除子类的重复代码，如果是接口，同样的功能因为接口只提供声明，所以一个子类就要写一遍，但是模板方法模式中，某些共有的不变的东西
* 子类不需要重复性的写，可以直接调用父类的去实现
*/
//父类
class TestPaper
{
public:
	void TestQuestion1()
	{
		cout << "第一题的答案选什么A[1] B[2] C[3] D[4]" << endl;
		cout << "选的答案：" << Answer1() << endl;
	}
	void TestQuestion2()
	{
		cout << "第2题的答案选什么A[a] B[b] C[c] D[d]" << endl;
		cout << "选的答案：" << Answer2() << endl;
	}
	void TestQuestion3()
	{
		cout << "第三题的答案选什么A[!] B[@] C[#] D[$]" << endl;
		cout << "选的答案：" << Answer3() << endl;
	}
protected:
	virtual string Answer1()
	{
		return "";  //供给子类去实现的，因为对于每个子类来说，试题都是一样的，可能会不同的只有选项的答案，所以将每一题的答案抽象出一个接口供给子类实现
	}
	virtual string Answer2()
	{
		return "";
	}
	virtual string Answer3()
	{
		return "";
	}
};
//学生类，继承试卷类，不用抄题了只需要写答案
class studentA : public TestPaper
{
public:
	string Answer1()
	{
		return "A";
	}
	string Answer2()
	{
		return "C";
	}
	string Answer3()
	{
		return "B";
	}
};
class studentB : public TestPaper
{
public:
	string Answer1()
	{
		return "D";
	}
	string Answer2()
	{
		return "B";
	}
	string Answer3()
	{
		return "A";
	}
};
int main()
{
	//具体实现，还是多态
	cout << "学生1号的答题纸：" << endl;
	TestPaper* student1 = new studentA;
	student1->TestQuestion1();
	student1->TestQuestion2();
	student1->TestQuestion3();
	cout << endl << "学生2号的答题纸：" << endl;
	TestPaper* student2 = new studentB;
	student2->TestQuestion1();
	student2->TestQuestion2();
	student2->TestQuestion3();

	system("pause");
	return 0;
}

