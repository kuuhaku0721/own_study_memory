/*
* Bingo 想知道他的考试成绩是否完美，请帮他判断。从键盘输入一个整数表示的成绩，编程判断成绩是否在 90~100 之
间，如果是则输出“Perfect”。
*/
#include <iostream>
#include <string>
using namespace std;
void perfect(int score)
{
	if (score >= 90 && score <= 100)
	{
		cout << "Perfect!" << endl;
	}
	else if (score > 100)
	{
		cout << "this is a wrong score" << endl;
	}
	else
	{
		cout << "not bad" << endl;
	}
}
int main()
{
	cout << "请输入成绩：";
	int score;
	cin >> score;
	perfect(score);

	system("pause");
	return 0;
}

