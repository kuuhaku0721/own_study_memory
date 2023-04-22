/*
* 编写你自己版本的翻转函数，通过调用接受左值引用和右值引用参数的函数来测试它
*/
#include <iostream>
#include <string>
#include<utility>
using namespace std;

//模板接受一个可调用对象和两个参数，将两个参数“翻转”后用来调用给定的可调用对象
template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(forward<T2>(t2), forward<T1>(t1));
}

void f(int v1, int& v2) //注意v2是一个引用
{
	cout << v1 << " " << ++v2 << endl;
}

void g(int&& i, int& j)
{
	cout << i << " " << j << endl;
}

//flip1实现不完整：顶层const和引用都丢掉了
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t2, t1);
}

int main()
{
	int i = 0, j = 0, k = 0, l = 0;
	cout << i << " " << j << " " << k << " " << l << endl;

	f(42, i); //f改变其实参i
	flip1(f, j, 42); //通过flip1调用f不会改变j
	flip2(f, k, 42); //正确，k被改变了
	//g(l, i);  //报错，无法将右值引用绑定到左值
	flip(g, i, 42); //正确：第三个参数的右值属性被保留了
	cout << i << " " << j << " " << k << " " << l << endl;

	system("pause");
	return 0;
}

