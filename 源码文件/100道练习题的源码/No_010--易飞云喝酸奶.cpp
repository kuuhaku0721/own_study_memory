/*
* 老师买了一箱酸奶，里面有 n 盒未打开的酸奶，Bingo 喜欢喝酸奶，第一时间发现了酸奶。
* Bingo 每 h 分钟能喝光一盒酸奶，并且 Bingo 在喝光一盒酸奶之前不会喝另一个
* 那么经过 m 分钟后还有多少盒未打开的酸奶？
* 输入三个数据分别是 n:总数 h:喝一盒的时间 m:经过一定时间
* 输入数据保证 m <= n * h  如8 5 16
*/
#include <iostream>
#include <string>
using namespace std;
void yogort(int n, int h, int m) //尽量使用float节省内存
{
	/*float les = m / h;
	int less = m / h;
	if (les - less != 0)
	{
		cout << n - less - 1 << endl;
	}
	else
	{
		cout << n - less << endl;
	}*/
	//然而可以一行解决
	cout << (m % h == 0) ? n - m / h : n - 1 - m / h;
}
int main()
{
	cout << "请输入三个数据：" << endl;
	int n, h, m;
	cin >> n >> h >> m;
	yogort(n, h, m);

	system("pause");
	return 0;
}

