/*
* Bingo 想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
* 闰年 能被四整除但不能被100整除  或者能被400整除
*/
#include <iostream>
#include <string>
using namespace std;
void days()
{
	cout << "请输入年份和月份：" << endl;
	int year, month;
	cin >> year >> month;
	bool run = false;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		run = true;
	}
	int day = 0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	case 2:
		if (run)
		{
			day = 29;
		}
		else
		{
			day = 28;
		}
		break;
	default:
		cout << "月份有误" << endl;
		break;
	}
	cout << year << "年" << month << "月有" << day << "天" << endl;
}
int main()
{
	days();

	system("pause");
	return 0;
}

