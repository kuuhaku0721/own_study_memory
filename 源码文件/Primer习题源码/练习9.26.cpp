/*删除元素*/
#include <iostream>
#include <string>
#include<list>
#include<vector>
using namespace std;

class Solution
{
public:
	void deleteElement()
	{
		int arr[] = { 0,1,1,2,3,5,8,13,21,55,89 };
		vector<int> v;
		list<int> L;

		v.assign(arr, arr + 11);
		L.assign(arr, arr + 11);

		auto vit = v.begin();
		while (vit != v.end())
		{
			if (!(*vit & 1)) //偶数
			{
				vit = v.erase(vit);
			}
			else
			{
				vit++;
			}
		}
		auto Lit = L.begin();
		while (Lit != L.end())
		{
			if (*Lit & 1) //奇数数
			{
				Lit = L.erase(Lit);
			}
			else
			{
				Lit++;
			}
		}
	}
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

