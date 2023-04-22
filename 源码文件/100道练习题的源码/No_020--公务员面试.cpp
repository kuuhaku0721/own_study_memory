/*
* Bingo 去面试公务员公务员面试现场打分。有 7 位考官，从键盘输入若干组成绩，每组 7 个分数（百分制），去掉一个最
高分和一个最低分，输出每组的平均成绩。
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
void avg()
{
	vector<int> v;
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int score;
		cin >> score;
		v.push_back(score);
		sum += score;
	}
	sort(v.begin(), v.end());
	sum = sum - *v.begin() - *(--v.end());
	cout << "平均分：" << fixed << setprecision(2) << sum / (v.size()-2) << endl;
}
int main()
{
	avg();

	system("pause");
	return 0;
}

