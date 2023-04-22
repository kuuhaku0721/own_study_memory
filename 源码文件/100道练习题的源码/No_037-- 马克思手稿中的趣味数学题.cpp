/*
* 马克思手稿中有一道趣味数学题：有 30 个人，其中有男人、女人和小孩，在一家
* 饭馆里吃饭共花了 50 先令，每个男人各花 3 先令，每个女人各花 2 先令，每个小
* 孩各花 1 先令，问男人、女人和小孩各有几人
*/
#include <iostream>
#include <string>
using namespace std;
void Marx()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if ((3 * i + 2 * j + (30 - i - j)) == 50 && i != 0 && j != 0 && (i+j) != 30)
			{
				cout << "男人：" << i << " 人" << endl;
				cout << "女人：" << j << " 人" << endl;
				cout << "小孩：" << 30 - i - j << " 人" << endl;
				cout << "----------------------------" << endl;
			}
		}
	}
	
}
int main()
{
	Marx();

	system("pause");
	return 0;
}

