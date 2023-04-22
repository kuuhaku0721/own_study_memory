/*
* ��дScreen��ģ�壬�÷����Ͳ�������Screen�ĸߺͿ�
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
	char get() const //��ȡ��괦����
	{
		return contents[cursor]; //������������
	}
	inline char get(int, int) const; //��ʾָ������
	Screen& clear(char = bkground);
private:
	static const char bkground = ' ';
public:
	Screen& move(int r, int c); //���ָ������
	Screen& set(char);
	Screen& set(int, int, char);
	//����display��ͨ�汾��const�汾
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
	//ʵ�������ʾ�ĺ���
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
	int row = r * W; //������λ��
	cursor = row + c; //������ƶ�������ָ����
	return *this; //���ص�ǰ������ֵ��
}

template<int H, int W>
char Screen<H, W>::get(int r, int c)const //�������Ѿ���������
{
	int row = r * W; //������λ��
	return contents[row + c]; //������ƶ�������ָ����
}

template<int H, int W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor] = c; //����괦����������Ϊ��ֵ
	return *this; //���ص�ǰ������ֵ��
}

template<int H, int W>
inline Screen<H, W>& Screen<H, W>::set(int r, int col, char ch)
{
	contents[r * W + col] = ch; //���ø���λ������Ϊ��ֵ
	return *this; //���ص�ǰ������ֵ��
}