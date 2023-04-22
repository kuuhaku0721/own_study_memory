/*
* 输入 n 科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。
* 两行输入第一行n个  第二个是成绩
*/
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
void sumScore()
{
	cout << "请输入成绩数量：";
	int n;
	cin >> n;
	vector<float> v;
	float sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		float score;
		cin >> score;
		v.push_back(score);
		sum += score;
	}
	sort(v.begin(),v.end());
	cout << "最高分：" << (*v.begin()) << endl;
	cout << "最低分：" << *(--v.end()) << endl;
	cout << "平均分：" << fixed << setprecision(2) << sum / v.size() << endl;
}
int main()
{
	sumScore();

	system("pause");
	return 0;
}

