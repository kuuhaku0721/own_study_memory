/*两个C++11新标准的容器*/
#include <iostream>
#include <string>
#include<tuple>
#include<bitset>
using namespace std;
/*
*  tuple是一个固定大小的不同类型值的集合，是泛化的std::pair。我们也可以把他当做一个通用的结构体来用，
* 不需要创建结构体又获取结构体的特征，在某些情况下可以取代结构体使程序更简洁，直观。
* std::tuple理论上可以有无数个任意类型的成员变量，而std::pair只能是2个成员，因此在需要保存3个及以上的数据时就需要使用tuple元组了。
*/
void testTuple()
{
	//1、tuple的创建和初始化
	int v1, v2;
	std::tuple<int, string, double> t1;            //创建一个空的tuple对象（使用默认构造），它对应的元素分别是T1和T2...Tn类型，采用值初始化。
	//std::tuple<int, string, double> t2(v1, v2, ... TN);    //创建一个tuple对象，它的两个元素分别是T1和T2 ...Tn类型; 要获取元素的值需要通过tuple的成员get<Ith>(obj)进行获取(Ith是指获取在tuple中的第几个元素，请看后面具体实例)。
	//std::tuple<T1&> t3(ref&); // tuple的元素类型可以是一个引用
	std::make_tuple(v1, v2); // 像pair一样也可以通过make_tuple进行创建一个tuple对象

	//2、tuple元素的查找
	std::tuple<int, char, double> mytuple(10, 'a', 3.14);

	std::cout << "mytuple has ";
	std::cout << std::tuple_size<decltype(mytuple)>::value;
	std::cout << " elements." << '\n';

	//3、获取tuple元素的值
	//获取tuple对象元素的值可以通过get<Ith>(obj)方法进行获取；Ith - 是想获取的元素在tuple对象中的位置。obj - 是想获取tuple的对象
	std::tuple<int, char, double> mytuple1(10, 'a', 3.14);

	std::cout << "mytuple has ";
	std::cout << std::tuple_size<decltype(mytuple)>::value;
	std::cout << " elements." << '\n';

		//获取元素
	std::cout << "the elements is: ";
	std::cout << std::get<0>(mytuple) << " ";
	std::cout << std::get<1>(mytuple) << " ";
	std::cout << std::get<2>(mytuple) << " ";

	std::cout << '\n';

	//4、  tuple不支持迭代，只能通过元素索引(或tie解包)进行获取元素的值。
	std::tuple<std::string, int, std::string, int> tp;
	tp = std::make_tuple("Sven", 25, "Shanghai", 21);

		// 定义接收变量
	std::string name;
	std::string addr;
	int ages;
	int areaCode;
		//利用tie进行解包
	std::tie(name, ages, addr, areaCode) = tp;
	std::cout << "Output: " << '\n';
	std::cout << "name: " << name << ", ";
	std::cout << "addr: " << addr << ", ";
	std::cout << "ages: " << ages << ", ";
	std::cout << "areaCode: " << areaCode << '\n';

}
/*
* bitset 相当于一个二进制的数组，并且可以直接用01串赋值
*/
void testBitset()
{
	//1、bitset的定义
	bitset<4> a1;//长度为4，默认以0填充
	bitset<8> a2;//长度为8，将12以二进制保存，前面用0补充


	string s = "100101";
	bitset<10> a3(s);//长度为10，前面用０补充

		//实验检测，char在普通环境不能直接赋值给bitset
		//要开c++11，针不戳
	char s2[] = "10101";
	bitset<13> a4(s2);//长度为13，前面用０补充
		//所以这玩意noip上不能用……

	cout << a1 << endl;//0000
	cout << a2 << endl;//00001100
	cout << a3 << endl;//0000100101
	cout << a4 << endl;//0000000010101


	//2、如果定义如果超出范围
	bitset<2> bitset1(12);//12的二进制为1100（长度为４），但bitset1的size=2，只取后面部分，即00

	string s1 = "100101";
	bitset<4> bitset2(s1);//s的size=6，而bitset的size=4，只取前面部分，即1001

	cout << bitset1 << endl;//00
	cout << bitset2 << endl;//1001

	//3、使用bitset的位运算
	bitset<4> foo(string("1001"));//这种赋值方式就可以直接用，没有限制
	bitset<4> bar(string("0011"));
	cout << (foo ^= bar) << endl;       // 1010 (foo对bar按位异或后赋值给foo)
	cout << (foo &= bar) << endl;       // 0010 (按位与后赋值给foo)
	cout << (foo |= bar) << endl;       // 0011 (按位或后赋值给foo)
	cout << (foo <<= 2) << endl;        // 1100 (左移２位，低位补０，有自身赋值)
	cout << (foo >>= 1) << endl;        // 0110 (右移１位，高位补０，有自身赋值)
	cout << (~bar) << endl;				// 1100 (按位取反) 
	cout << (bar >> 1) << endl;         // 0001 (右移，不赋值)
	cout << (foo == bar) << endl;       // （0）false (0110==0011为false)
	cout << (foo != bar) << endl;       // （1）true  (0110!=0011为true)
	cout << (foo & bar) << endl;        // 0010 (按位与，不赋值)
	cout << (foo | bar) << endl;        // 0111 (按位或，不赋值)
	cout << (foo ^ bar) << endl;		// 0101 (按位异或，不赋值)

	//4、bitset中单一元素的访问和修改
	bitset<4> a22("1011");//这个赋值方法只能在c++11里用，noip八行

		//可以用上面位运算时的方法
	bitset<4> a33(string("1011"));

	cout << a33[0] << endl;//1
	cout << a33[1] << endl;//1
	cout << a33[2] << endl;//0
	cout << a33[3] << endl;//1
		//注意！这两种赋值方式都是反序赋值的
		//所以输出值为1101；
		//可以直接输出a1来输出正序

		//bitset支持单点修改
	a22[0] = 0;
	cout << a22[0] << endl;//0
	cout << a22 << endl;//0101

	//5、bitset中的各种函数
	bitset<8> foo1(string("10011011"));

	cout << foo1.count() << endl;//5　　（count函数用来求bitset中1的位数，foo中共有５个１
	cout << foo1.size() << endl;//8　　（size函数用来求bitset的大小，一共有８位

	cout << foo1.test(0) << endl;//true　　（test函数用来查下标处的元素是０还是１，并返回false或true，此处foo[0]为１，返回true
	cout << foo1.test(2) << endl;//false　　（同理，foo[2]为０，返回false

	cout << foo1.any() << endl;//true　　（any函数检查bitset中是否有１
	cout << foo1.none() << endl;//false　　（none函数检查bitset中是否没有１
	cout << foo1.all() << endl;//false　　（all函数检查bitset中是全部为１
}

int main()
{
	testTuple();
	testBitset();

	system("pause");
	return 0;
}

