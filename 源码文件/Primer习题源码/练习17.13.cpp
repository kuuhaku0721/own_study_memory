/*
* 编写一个整型对象，包含真假测验的正确答案
* 一个函数接受一个问题编号和一个表示真假答案的值，函数根据这两个参数更新测验的解答
* 
* 使用bitset
*/
#include <iostream>
#include<bitset>
using namespace std;

template<size_t N>
class exam
{
public:
	exam() : s() {}
	size_t get_size() { return N; }
	void set_solution(size_t n, bool b) { s.set(n, b); }
	bitset<N> get_solution() const { return s; }
	size_t score(const bitset<N>& a);
private:
	bitset<N> s;
};

template<size_t N>
size_t exam<N>::score(const bitset<N>& a)
{
	size_t ret = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (s[i] == a[i])
			ret++;
	}
	return ret;
}

int main()
{
	exam<80> e;
	e.set_solution(0, 1);
	e.set_solution(79, 1);
	cout << e.get_solution() << endl;

	bitset<80> a;
	cout << e.get_size() << "题对了" << e.score(a) << "题" << endl;

	system("pause");
	return 0;
}

