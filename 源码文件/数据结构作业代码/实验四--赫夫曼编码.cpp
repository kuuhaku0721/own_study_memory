/*
* 给定报文中26个字母a-z及空格的出现频率
* {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168}，
* 构建哈夫曼树并为这27个字符编制哈夫曼编码，并输出。
* 模拟发送端，从键盘输入字符串，以%为结束标记，在屏幕上输出输入串的编码；
* 模拟接收端，从键盘上输入0-1哈夫曼编码串，翻译出对应的原文。
*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct HuffmanNode  //哈夫曼树的结点结构
{
	int weight; //权重，数据点的出现频率
	char ch; //存储的符号，树上的符号
	string code;  //符号的编码
	int leftChild, rightChild, parent;  //左，右孩子，父结点  //没有用结点表示而是用数据值的位置来构成父子关系
};

class HuffmanCode
{
public:
	HuffmanCode(char arrChar[], int len1, int arrWeight[], int len2); //构造函数
	~HuffmanCode(); //析构
	void getMin(int& first, int& second, int parent); // 选取两个较小的元素
	void Merge(int first, int second, int parent); // 合并
	void EnCode(); //编码
	void printEnCode(); //输出编码
	void Decode(); //解码-二进制转字符
	void StrEncode(); //解码-字符转二进制


private:
	HuffmanNode* HuffmanTree; //数组,用以保存树上的结点
	int leafSize;  //统计字符的总个数  /*其实就是27个*/
};

//构造
HuffmanCode::HuffmanCode(char arrChar[], int len1, int arrWeight[], int len2)
{
	int len = len1;  //长度就是两个数组的长度
	HuffmanTree = new HuffmanNode[256]; //动态分配空间

	//1.初始化HuffmanTree数组,开辟空间，建立关系，给初始空值
	for (int i = 0; i < (2 * len - 1); i++) //叶子结点为len，则树最多有2*len-1 个结点
	{
		HuffmanTree[i].leftChild = HuffmanTree[i].rightChild = HuffmanTree[i].parent = -1; //建立起左右子树及父结点之间的关系
		HuffmanTree[i].code = ""; //初始编码赋空
	}

	//2.记录字符串的各个字符出现的个数
	leafSize = 0; //统计字符数
	for (int i = 0; i < 27; i++)
	{
		HuffmanTree[i].ch = arrChar[i];  //字符
		HuffmanTree[i].weight = arrWeight[i]; //权重
		leafSize++;
	}

	//3.选取两个较小值合并，使其成为树的结构
	int first, second; //两个较小结点
	for (int i = leafSize; i < (2 * leafSize - 1); i++)
	{
		getMin(first, second, i); //选择两个较小的元素
		Merge(first, second, i); //合并在一块 构成一条树分支
	}

	cout << "构造函数，初始化完成" << endl;
}
//选择两个较小的元素
void HuffmanCode::getMin(int& first, int& second, int parent)
{
	double weight = 0;
	int i;
	//找权重最小的元素
	for ( i = 0; i < parent; i++)
	{
		if (HuffmanTree[i].parent != -1)
		{
			//已选过，直接跳过
			continue;
		}
		if (weight == 0)
		{
			//第一次找到没选过的点
			weight = HuffmanTree[i].weight;
			first = i;
		}
		else if (HuffmanTree[i].weight < weight)
		{
			//更小的权值
			weight = HuffmanTree[i].weight;
			first = i;  //一直找到权值最小的那个
		}
	}
	//再找权值第二小的那个
	weight = 0;
	for ( i = 0; i < parent; i++)
	{
		if (HuffmanTree[i].parent != -1 || i == first)
		{
			//已选过，直接跳过
			continue;
		}
		if (weight == 0)
		{
			//第一次找到没选过的点
			weight = HuffmanTree[i].weight;
			second = i;
		}
		else if (HuffmanTree[i].weight < weight)
		{
			//权值更小
			weight = HuffmanTree[i].weight;
			second = i;
		}
	}
}
//合并
void HuffmanCode::Merge(int first, int second, int parent)
{
	HuffmanTree[first].parent = HuffmanTree[second].parent = parent; //这俩父结点相同
															//最终效果		 parent
	HuffmanTree[parent].leftChild = first;   //给父结点设置俩孩子           |      |
	HuffmanTree[parent].rightChild = second; //                       leftChild   rightChild

	HuffmanTree[parent].weight = HuffmanTree[first].weight + HuffmanTree[second].weight; //父结点权值等于孩子的和
}
//析构
HuffmanCode::~HuffmanCode()
{
	delete[] HuffmanTree;
}

//编码：利用哈夫曼1编码原理对数据进行加密
void HuffmanCode::EnCode()
{
	string code;  //因为每个编码长度不一样所以用string类型保存
	int i, j, k, parent;
	for ( i = 0; i < leafSize; i++) //从叶子结点出发
	{
		j = i;
		code = ""; //初始化为空
		while (HuffmanTree[j].parent != -1)  //往上找到根结点
		{
			parent = HuffmanTree[j].parent; //父结点
			if (j == HuffmanTree[parent].leftChild) //如果是左孩子，记为0
			{
				code += "0";
			}
			else //右孩子，记为1
			{
				code += "1";
			}
			j = parent; //上移到父结点
		}
		//最终编码要倒过来，因为代码是从叶子往上走到根，而实际编码是从根走到叶子
		for ( k = (int)code.size() - 1; k >= 0; k--)
		{
			HuffmanTree[i].code += code[k]; //保存编码到树上
		}
	}

	cout << "编码完成" << endl;
	system("pause");
	system("cls");
	return;
}
//输出编码
void HuffmanCode::printEnCode()
{
	for (int i = 0; i < leafSize; i++)
	{
		cout << "字符：" << HuffmanTree[i].ch << "的编码为：" << HuffmanTree[i].code << " " << endl;
	}

	/*system("pause");  //后续还需要对照编码表来输入，这里不做清屏返回操作
	system("cls");
	return;*/
}

//解码----01二进制解码字符
void HuffmanCode::Decode()
{
	cout << "请输入想要解码的一串编码：" << endl;  //用cin可以解决输入的问题，但是cin遇到空格就停掉了，所以只能在这里用，所以只有这个支持自定义输入
	string str;
	cin >> str;

	string decode, temp; //decode保存整个解码，temp保存每个字符的解码
	int len = (int)str.size(); //编码的长度
	int i, j;

	decode = temp = ""; //初始置空
	for ( i = 0; i < len; i++)
	{
		temp += str[i]; //加一个编码
		for ( j = 0; j < leafSize; j++)
		{
			if (HuffmanTree[j].code == temp) //叶子结点找到对应的编码
			{
				decode += HuffmanTree[j].ch; //转成相应字符
				temp = ""; //再次置空
				break;
			}
		}
		if (i == len - 1 && j == leafSize)//遍历完还没找到对应的,说明没有
		{
			cout << "解码出错，输入存在错误字符" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	cout << "解码为：" << decode << endl;

	cout << "解码完成" << endl;
	system("pause");
	system("cls");
	return;
}


//拿到字符数组的长度
int getCharSize(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
//解码---字符转二进制
void HuffmanCode::StrEncode()
{
	string str = "i love you";  //很奇怪的是，这里的str只能用默认值，不能用输入值，cin（会忽略空格不能用），
								//其他的比如scanf，getline，cin.get, cin.getline,gets(),全都不能用，会直接无法输入
								//但是仅作测试的话，一个数据也差不多能用
	/*string str;
	cout << "输入：" << endl;  //用cin可以正常输入，但是cin会到空格停，所以只能输入连续的字符串中间不能有空格分隔
	cin >> str;*/

	cout << "当前字符串为：" << str << endl;
	int len = (int)str.size();

	/*char str[30];
	cout << "输入：" << endl;
	int cnt = 0;
	char a;
	while (cin >> a)
	{
		if (cin.get() == '%')   //用这个输入模式，输入进去的字符会乱码，
		{						//o 和 e 没法保存，空格没法保存，长度没法正常记录，超出输入长度的会乱码，无法正常保存输入值
			break;
		}
		str[cnt] = a;
		cnt++;
	}
	cout << str << endl;
	int len = getCharSize(str);*/
	
	string code; //code保存编码出的二进制字符串
	char temp; //temp用于保存当前这个字符
	int i, j;

	code = ""; //初始置空
	for (i = 0; i < len; i++)
	{
		temp = str[i]; //拿到一个字符
		for (j = 0; j < leafSize; j++)
		{
			if (HuffmanTree[j].ch == temp) //叶子结点找到对应的字符
			{
				code += HuffmanTree[j].code; //转成相应编码
				break; //退出当前循环
			}
		}
		if (i == len - 1 && j == leafSize)//遍历完没找到对应的
		{
			cout << "解码出错，输入存在错误字符" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	cout << "解码为：" << code << endl;

	cout << "解码完成" << endl;
	system("pause");
	system("cls");
	return;
}

//打印编码的参数
void displayElement(char arrChar[], int len1, int arrWeight[], int len2)
{
	cout << "HuffmanTree的参数如下：" << endl;
	for (int i = 0; i < len1; i++)  //这里的len1和len2是一样的，其实完全可以只传一个len
	{
		cout << "字符：" << arrChar[i] << " 权值：" << arrWeight[i] << endl;  //依次将Tree的char 和 weight 输出
	}

	system("pause");
	system("cls");
	return;
}
//启动页面
void start()
{
	//这是哈夫曼树要用的参数表
	char arrChar[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
	int arrWeight[27] = { 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168 };
	//初始化HuffmanTree
	HuffmanCode huffman(arrChar, 27, arrWeight, 27);   //这里两个27是字符串的长度，按照规范填一下参数，以备后续更改长度，实际本案例中没必要

	while (true)
	{
		/*第一次之后跟改成输入的形式，构造函数参数放两个数组，参数就是俩数组*/
		/*初始化就用现在这个，之后要不单独做出来一个函数*/
		/*默认输入都是正确的，不再做各项输入错误如树为空等的判断*/
		cout << "***********************************************************" << endl;
		cout << "***   1--输出HuffmanTree的参数                          ***" << endl; //输出参数表
		cout << "***   2--初始化HuffmanTree的参数(含有26个字母及空格)    ***" << endl; //构造？初始化没必要输出
		cout << "***   3--创建HuffmanTree和编码表                        ***" << endl; //编码？初始化也没必要输出
		cout << "***   4--输出编码表                                     ***" << endl; //输出编码表
		cout << "***   5--输入编码并翻译为字符                           ***" << endl; //测试
		cout << "***   6--输入字符，并实现转码                           ***" << endl; //测试
		cout << "***   7--退出                                           ***" << endl;
		cout << "***********************************************************" << endl;
		cout << "请输入：" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:  //打印参数
			displayElement(arrChar, 27, arrWeight, 27);
			break;
		case 2:  //初始化HuffmanTree的参数
			cout << "初始化已完成" << endl;
			system("pause");
			system("cls");
			break;
		case 3:  //编码
			huffman.EnCode();
			break;
		case 4:  //输出编码表
			huffman.printEnCode();
			break;
		case 5:  //二进制解码
			huffman.Decode();
			break;
		case 6:  //字符串加密
			huffman.StrEncode();
			break;
		case 7:
			cout << "退出成功" << endl;
			return;
		default:
			system("cls");
			break;
		}
	}
}

int main()
{
	//实验报告用代码不再分hpp和cpp文件，留存的代码分出去.h文件和.hpp .cpp文件 方便后续管理和查看
	start();
	
	


	system("pause");
	return 0;
}

