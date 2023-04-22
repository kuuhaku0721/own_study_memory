/*方程实在没法在这里放，看课本吧，第三章习题算法题第九题*/
#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//递归实现
	int Ack(int m, int n)
	{
		if (m == 0)
		{
			return n + 1;
		}
		if (m != 0 && n == 0)
		{
			return Ack(m - 1, 1);
		}
		if (m != 0 && n != 0)
		{
			return Ack(m - 1, Ack(m, n - 1));
		}
	}
	//非递归实现
	int Ack_non(int m, int n)
	{
		int akm[m + 1][100];  //这里在vs的MSVC没法通过编译，但是在VSCode的MinGW可以过编译，so....Fuck you
		for (int j = 0; j < 100; j++)
			akm[0][j] = j + 1;
		for (int i = 1; i <= m; i++)
		{ 
			akm[i][0] = akm[i - 1][1];
			for (int j = 1; j < 100; j++)
				akm[i][j] = akm[i - 1][akm[i][j - 1]];
		}
		return akm[m][n];
	}
};

int main()
{
	int ret = Solution().Ack(2, 1);
	int ret2 = Solution().Ack_non(2, 1);

	cout << ret << endl << ret2 << endl;

	system("pause");
	return 0;
}

