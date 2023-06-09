/*
* 编写Screen类模板，用非类型参数定义Screen的高和宽
*/
#include <iostream>
#include <string>

template <int H, int W>
class Screen
{
public:
	Screen() : contents(H* W, ' ') {}
	Screen(char c) : contents(H* W, c) {}
	friend class Window_mgr;
	char get() const //获取光标处内容
	{
		return contents[cursor]; //隐含是内联的
	}
	inline char get(int, int) const; //显示指定内联
	Screen& clear(char = bkground);
private:
	static const char bkground = ' ';
public:
	Screen& move(int r, int c); //随后指定内联
	Screen& set(char);
	Screen& set(int, int, char);
	//重载display普通版本和const版本
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}
private:
	//实际完成显示的函数
	void do_display(std::ostream& os) const
	{
		os << contents;
	}
	int cursor = 0;
	std::string contents;
};

template<int H, int W>
Screen<H, W>& Screen<H, W>::clear(char c)
{
	contents = std::string(H * W, c);
	return *this;
}

template<int H, int W>
inline
Screen<H, W>& Screen<H, W>::move(int r, int c)
{
	int row = r * W; //计算行位置
	cursor = row + c; //将光标移动到此行指定列
	return *this; //返回当前对象（左值）
}

template<int H, int W>
char Screen<H, W>::get(int r, int c)const //在类内已经声明内联
{
	int row = r * W; //计算行位置
	return contents[row + c]; //将光标移动到此行指定列
}

template<int H, int W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor] = c; //将光标处的内容设置为新值
	return *this; //返回当前对象（左值）
}

template<int H, int W>
inline Screen<H, W>& Screen<H, W>::set(int r, int col, char ch)
{
	contents[r * W + col] = ch; //设置给定位置内容为新值
	return *this; //返回当前对象（左值）
}