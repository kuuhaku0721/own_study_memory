/*
* 某学生的记录由学号、8 门课程成绩和平均分组成，学号和 8 门课程的成绩已在主
* 函数中给出。请编写函数 fun，它的功能是：求出该学生的平均分放在记录的 ave
* 成员中。请自己定义正确的形参
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Student
{
public:
	Student(vector<int>& v)
	{
		this->v = v;
	}
	string stdID = "110120119";
	vector<int> v;
	float avg;
};
void fun(Student* s)
{
	int sum = 0;
	vector<int> vt = s->v;
	for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		sum += *it;
	}
	s->avg = sum / 8;
}
int main()
{
	vector<int> v;
	v.push_back(90);
	v.push_back(91);
	v.push_back(92);
	v.push_back(93);
	v.push_back(94);
	v.push_back(95);
	v.push_back(96);
	v.push_back(97);
	Student s1(v);
	fun(&s1);
	cout << "平均分：" << s1.avg << endl;

	system("pause");
	return 0;
}

