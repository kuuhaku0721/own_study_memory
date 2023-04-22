/*
* 作为基类用于后续练习题
*/
#include <iostream>
#include <string>
#include<ostream>
#include<set>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) : bookNo(book), price(sales_price)
	{
		cout << "Quote constructor is running" << endl;
	}
	string isbn() const
	{
		return bookNo;
	}
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	//为你的Quote类体系添加一个名为debug的虚函数，令其分别显示每个类的数据成员
	virtual void debug()
	{
		cout << "bookNo= " << bookNo << " price=" << price << endl;
	}
	virtual ~Quote()  //对析构函数进行动态绑定
	{
		cout << "Quote destructor is running" << endl;
	}

	friend ostream& operator<<(ostream&, Quote&);
private:
	string bookNo; //书籍的ISBN编号
protected:
	double price = 0.0;  //代表普通状态下不打折的价格
};
ostream& operator<<(ostream& os, Quote& e)
{
	os << "\tUsing operator << (ostream&, Quote&);" << endl;
	return os;
}

class Bulk_quto : public Quote
{
public:
	Bulk_quto(const string& book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) : Quote(book, sales_price), min_qty(qty), discount(disc)
	{
		cout << "Bulk_constructor is running" << endl;
	}
	double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
		{
			return cnt * (1 - discount) * price;
		}
		else
		{
			return cnt * price;
		}
	}
	virtual void debug()
	{
		Quote::debug(); //bookNo变量为private，所以不能直接访问bookNo只能调用基类的debug()来显示
		cout << "min_qty= " << min_qty << " discount= " << discount << endl;
	}
	~Bulk_quto()
	{
		cout << "Bulk_quto destructor is running" << endl;
	}

private:
	size_t min_qty;
	double discount;
};
ostream& operator<<(ostream& os, Bulk_quto& bq)
{
	os << "\tUsing operator<<(ostream&, Bulk_quto&);" << endl;
	return os;
}

//定义你自己的Disc_quote和Bulk_quote实现不同的折扣策略
class Disc_quote : public Quote
{
public:
	Disc_quote(const string& book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) : Quote(book, sales_price), quantity(qty), discount(disc) {}
	virtual double new_price(size_t cnt) const = 0;
protected:
	size_t quantity;
	double discount;
};
class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote(const string& book = "", double sales_price = 0, size_t qty = 0, double disc_rate = 0) : Disc_quote(book, sales_price, qty, disc_rate) {}

	double new_price(size_t cnt) const
	{
		if (cnt > quantity)
		{
			return cnt * (1 - discount) * price;
		}
		else
		{
			return cnt * price;
		}
	}
};


//定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣
//如果购买量一旦超过了限量，则超出的部分以原价销售
class Limited_quote : public Disc_quote
{
public:
	Limited_quote(const string& book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0) : Disc_quote(book, sales_price, qty, disc_rate) {}

	double net_price(size_t cnt) const override
	{
		if (cnt << min_qty)
		{
			return cnt * (1 - discount) * price;
		}
		else
		{
			return quantity * (1 - discount) * price + (cnt - quantity) * price;
		}
	}
private:
	size_t min_qty;
	double discount;
};

double print_total(ostream& os, const Quote& item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者Bulk_quote::net_price(n)
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold: " << n << "total due: " << ret << endl;
	return ret;
}

//编写你自己的Basket类，用它计算上一个交易记录的总价格
class Basket
{
public:
	//Basket使用合成的默认构造和拷贝控制成员
	void add_item(const shared_ptr<Quote>& sale)
	{
		it
	}
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(ostream&) const;
private:
	//该函数用于比较shared_ptr, multiset成员会用到它
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	//multiset保存多个报价，按照compare成员排序
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0; //保存实时计算出的总价格
	//iter指向isbn相同的一批元素中的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素的最后一个的下一位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		//我们知道在当前的Basket中至少有一个该关键字的元素
		//打印该书籍对应的项目
		sum += print_total(os, *(*iter), items.count(*iter));
	}
	os << "Total sale: " << sum << endl; //打印最终总价格
	return sum;

}

int main()
{
	Quote base("C++ Primer", 128.0);
	Bulk_quto bulk("Core Phython Programming", 89, 5, 0.19);
	cout << base << endl;
	cout << bulk << endl;

	system("pause");
	return 0;
}

