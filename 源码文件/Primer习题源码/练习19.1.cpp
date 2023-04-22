/*
* 使用malloc编写你自己版本的operator new(size_t)函数，使用free编写operator delete(void *)函数
*/
#include <iostream>
#include <string>
#include<new>
using namespace std;

void* operator new (size_t size)
{
	if (void* mem = malloc(size))
	{
		return mem;
	}
	else
	{
		throw bad_alloc();
	}
}

//编译时必须指定C++11，否则noexcept会导致编译错误
void operator delete(void* mem) noexcept
{
	free(mem);
}

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

