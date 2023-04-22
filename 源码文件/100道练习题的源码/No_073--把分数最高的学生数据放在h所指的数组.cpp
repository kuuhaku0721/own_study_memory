/*
* 学生的记录由学号和成绩组成，n 名学生的数据已在主函数中放入结构体数组 s
* 中，请编写函数 fun，它的功能使：把分数最高的学生数据放在 h 所指的数组中，
* 注意：分数最高的学生可能不止一个，函数返回分数最高的学生的人数
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Student
{
public:
	Student()
	{
		//无参空构造
	}
	Student(string stuNum, float score)
	{
		this->stuNum = stuNum;
		this->score = score;
	}
	string stuNum;
	float score;
};
void transformStuData(vector<Student>& v)
{
	//主函数添加学生数据，函数体判断学生成绩，如果是最高就放入数组，最后输出数组的size和分数
	vector<Student> h;
	Student s1 = v[0];
	//先找到最大的
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it).score >= s1.score)
		{
			s1 = *it;
		}
	}
	//想用谓词，但是不会用
	//谓词需要传入确定的一个值，可以传类对象进去然后用类对象寻找成员对象，也可以传两个参数，
	//但是不知道怎么把一个确定的值和另一个需要判断的类对象一块传进去，可能有办法，但是不会写
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it).score == s1.score)
		{
			h.push_back(*it);
		}
	}
	cout << "个数：" << h.size() << endl;
	for (int i = 0; i < h.size(); i++)
	{
		cout << h[i].stuNum << "--" << h[i].score << "分" << endl;
	}
}
int main()
{
	vector<Student> v;
	Student s1("123456001", 92.5);
	Student s2("123456002", 94.0);
	Student s3("123456003", 92.5);
	Student s4("123456004", 98.5);
	Student s5("123456005", 91.0);
	Student s6("123456006", 97.0);
	Student s7("123456007", 95.5);
	Student s8("123456008", 98.5);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	v.push_back(s6);
	v.push_back(s7);
	v.push_back(s8);
	transformStuData(v);

	system("pause");
	return 0;
}

