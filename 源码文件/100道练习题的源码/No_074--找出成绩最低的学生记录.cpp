/*
* 已知学生的记录由学号和学习成绩构成，n 名学生的数据已存入 a 结构体数组中。
* 请编写函数 fun，该函数的功能是：找出成绩最低的学生记录，通过形参返回主函
* 数(规定只有一个最低分)。
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
void findTheMin(vector<Student>& v)
{
	Student s1 = v[0];
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it).score < s1.score)
		{
			s1 = *it;
		}
	}
	cout << "最小的：" << s1.stuNum << "--" << s1.score  << "分" << endl;
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
	findTheMin(v);

	system("pause");
	return 0;
}

