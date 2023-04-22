/*
* 编写模板版本的print，它接受一个数组的引用，能处理任意大小，任意元素类型的数组
*/
#include <iostream>
#include <string>
using namespace std;

template<typename T, size_t N>
void print(const T(&a)[N])
{
	for (auto iter = begin(a); iter != end(a); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}
//上面的模板用到了begin和end 这两个也是标准库模板
//下面模仿标准库编写自己的begin和end,begin应返回数组首元素指针，end返回尾后指针，即在begin上加上数组大小N即可
template <typename T, size_t N>
const T* my_begin(const T(&a)[N])
{
	return &a[0];
}

template <typename T, size_t N>
const T* my_end(const T(&a)[N])
{
	return &a[0] + N;
}


int main()
{
	int a[6] = { 0,2,4,6,8,10 };
	string vs[3] = { "Hello", "World", "!" };


	print(a);
	print(vs);

	system("pause");
	return 0;
}

