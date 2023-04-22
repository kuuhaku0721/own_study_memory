/*
* 测试C++的文件操作
* 包括 创建 读取 写入 关闭 删除
*/
/*
* ifstream  专门读取
* ofstream  专门写入
* fstream   可读可写
* 头文件<fstream>
* 
* open()				打开指定文件，使其与文件流对象相关联。
* is_open()				检查指定文件是否已打开。
* close()				关闭文件，切断和文件流对象的关联。
* swap()				交换 2 个文件流对象。
* operator>>			重载 >> 运算符，用于从指定文件中读取数据。
* gcount()				返回上次从文件流提取出的字符个数。该函数常和 get()、getline()、ignore()、peek()、read()、readsome()、putback() 和 unget() 联用。
* get()					从文件流中读取一个字符，同时该字符会从输入流中消失。
* getline(str,n,ch)		从文件流中接收 n-1 个字符给 str 变量，当遇到指定 ch 字符时会停止读取，默认情况下 ch 为 '\0'。
* ignore(n,ch)			从文件流中逐个提取字符，但提取出的字符被忽略，不被使用，直至提取出 n 个字符，或者当前读取的字符为 ch。
* peek()				返回文件流中的第一个字符，但并不是提取该字符。
* putback(c)			将字符 c 置入文件流（缓冲区）。
* operator<<			重载 << 运算符，用于向文件中写入指定数据。
* put()					向指定文件流中写入单个字符。
* write()				向指定文件中写入字符串。
* tellp()				用于获取当前文件输出流指针的位置。
* seekp()				设置输出文件输出流指针的位置。
* flush()				刷新文件输出流缓冲区。
* good()				操作成功，没有发生任何错误。
* eof()					到达输入末尾或文件尾。
*/
/*
* 打开文件方式
* ios::in								打开文件用于读取数据。如果文件不存在，则打开出错。
* ios::out								打开文件用于写入数据。如果文件不存在，则新建该文件；如果文件原来就存在，则打开时清除原来的内容。
* ios::app								打开文件，用于在其尾部添加数据。如果文件不存在，则新建该文件。
* ios::ate								打开一个已有的文件，并将文件读指针指向文件末尾（读写指 的概念后面解释）。如果文件不存在，则打开出错。
* ios:: trunc							打开文件时会清空内部存储的所有数据，单独使用时与 ios::out 相同。
* ios::binary							以二进制方式打开文件。若不指定此模式，则以文本模式打开。
* ios::in | ios::out					打开已存在的文件，既可读取其内容，也可向其写入数据。文件刚打开时，原有内容保持不变。如果文件不存在，则打开出错。
* ios::in | ios::out					打开已存在的文件，可以向其写入数据。文件刚打开时，原有内容保持不变。如果文件不存在，则打开出错。
* ios::in | ios::out | ios::trunc		打开文件，既可读取其内容，也可向其写入数据。如果文件本来就存在，则打开时清除原来的内容；如果文件不存在，则新建该文件。
*/
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
void test01()
{
	const char* word = "hello world";
	fstream fs;
	fs.open("texttt.txt", ios::out);
	fs.write(word, 30);
	fs.close();
}
void test02()
{
	//测试文件是否打开成功
	ifstream ifile;
	ifile.open("texttt.txt", ios::in);
	if (ifile)
	{
		cout << "打开成功" << endl;
		ifile.close();
	}
	else
	{
		cout << "文件不存在或打开失败" << endl;
	}
	ofstream ofile;
	const char* path = "C:\\temp\\text.txt";
	ofile.open(path, ios::out | ios::in);
	if (ofile)
	{
		cout << "ofile打开成功" << endl;
		ofile.close();
	}
	else
	{
		cout << "文件不存在或打开失败" << endl;
	}
}
void test03()
{
	ifstream iFile;
	iFile.open("num.txt", ios::in);
	ofstream oFile;
	oFile.open("texttt.txt", ios::app);
	int sum = 0;
	int x;
	while (iFile >> x)
	{
		sum += x;
		oFile << x << endl;
	}
	oFile << "sum= " << sum << endl;

	iFile.close();
	oFile.close();
}
int main()
{
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}

