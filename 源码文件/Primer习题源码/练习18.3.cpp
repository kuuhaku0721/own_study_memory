/*
* 一些异常处理块
*/
#include <iostream>
#include <string>
#include<vector>
#include<exception>
using namespace std;

void exercise(int* b, int* e)
{
	//方法一：将有可能发生异常的代码放在try块中，以便在异常发生时捕获异常
	vector<int> v(b, e);
	int* p = new int[v.size()];
	try {
		ifstream in("ints");
		//此处发生异常
	}
	catch(exception e){
		delete p; //释放数组
		//进行其他处理
	}
}

class Resource
{
public:
	Resource(size_t sz) : r(new int[sz]) {}
	~Resource() { if (r) delete r; }
private:
	int* r;
};
//相应的exercise函数修改为
void exercise_1(int* b, int* e)
{
	vector<int> v(b, e);
	Resource res(v.size());
	ifstream in("ints");  //异常发生在这里
}

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

