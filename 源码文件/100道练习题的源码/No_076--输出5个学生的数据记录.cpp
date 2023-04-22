/*
* 编写 input()和 output()函数输入，输出 5 个学生的数据记录。
*（用结构体设计，学生记录中包括学号、姓名、四门课程成绩）
*/
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	void input(string stuNum, string name, float Yuwen, float math, float English, float Union)
	{
		this->stuNum = stuNum;
		this->name = name;
		this->Yuwen = Yuwen;
		this->math = math;
		this->English = English;
		this->Union = Union;
	}
	void output()
	{
		cout << "学号：" << stuNum << " 姓名：" << name << endl
			<< "语文：" << Yuwen << endl
			<< "数学：" << math << endl
			<< "英语：" << English << endl
			<< "综合：" << Union << endl;
	}
private:
	string stuNum; //学号
	string name; // 姓名
	float Yuwen; //语文 数学 英语 综合
	float math;
	float English;
	float Union;
};
void test01()
{
	//测试就用俩数据
	Student s1;
	Student s2;
	s1.input("1234560001", "张三", 108, 123, 120, 216);
	s2.input("1234560002", "李四", 115, 134, 108, 231);

	s1.output();
	s2.output();
}
int main()
{
	test01();

	system("pause");
	return 0;
}

