/*
* 要求链表顺序存储结构，删除链表中所有值为item的元素，并且时间复杂度O(n)，空间复杂度O(1)
*/
#include <iostream>
using namespace std;
struct arrList
{
	int data[10] = { 0 }; //默认大小为10的数组
	int count = 0; //数组内数据量
};

class Solution
{
public:
	void eraseItemInArr(arrList*& arr, int item)
	{
		int begin = 0;
		int end = arr->count - 1;
		while (begin < end)   //设置双指针，从头遍历，如果左端为item，从右端开始找到第一个不是item的值赋值给当前位置，然后左端前进一步，右端向左一步
		{                     //如果左端不是item，左端前进，右端不动，题目没要求数据的前后顺序所以随便换
			if (arr->data[begin] == item)
			{
				while (begin < end && arr->data[end] == item) end--;  
				arr->data[begin] = arr->data[end];
				begin++;
				end--;
			}
			else
			{
				begin++;
			}
		}
		arr->count = begin - 1;
	}
};

int main()
{
	int ia[10] = { 3,3,3,3,3,5,3,3,8,3 };
	arrList* arr = new arrList;
	for (int i = 0; i < 10; i++)
	{
		arr->data[i] = ia[i];
		arr->count++;
	}
	Solution().eraseItemInArr(arr, 3);

	for (int i = 0; i < arr->count; i++)
	{
		cout << arr->data[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}

