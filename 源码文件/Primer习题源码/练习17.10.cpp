/*
* 使用序列1，2，3，5，8，13，21初始化一个bitset，将这些位置位
* 对另一个bitset进行默认初始化，并编写一小段程序将其恰当的位置位
*/
#include <iostream>
#include <string>
#include<bitset>
using namespace std;

int main()
{
	unsigned bp = 2 | (11 << 2) | (1 << 5) | (1 << 8) | (1 << 13) | (1 << 21);
	bitset<32> bv(bp);
	cout << bv << endl;

	bitset<32> bv1;
	bv1.set(1);
	bv1.set(2);
	bv1.set(3);
	bv1.set(5);
	bv1.set(8);
	bv1.set(13);
	bv1.set(21);
	cout << bv1 << endl;

	system("pause");
	return 0;
}

