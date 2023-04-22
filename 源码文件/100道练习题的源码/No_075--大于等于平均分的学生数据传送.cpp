/*
* 学生的记录是由学号和成绩组成，n 名学生的数据已在主函数中放入结构体数组 s
* 中，请编写函数 fun，它的功能是：把高于等于平均分的学生数据放在 b 所指的数
* 组中，高于等于平均分的学生人数通过形参 n 传回，平均分通过函数值返回
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
void biggerAvg(vector<Student>& v)
{
	vector<Student> h;
	float sum = 0.0;
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		sum += (*it).score;
	}
	double avg = sum / v.size();
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it).score >= avg)
		{
			h.push_back(*it);
		}
	}
	cout << "平均分：" << avg << endl;
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
	biggerAvg(v);

	system("pause");
	return 0;
}

