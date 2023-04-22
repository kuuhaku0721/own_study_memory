﻿/*
* 栈 匹配括号
* 懂？
*/
#include <iostream>
#include <string>
#include<deque>
#include<stack>
#include<stdexcept>
using namespace std;

//表示栈中对象的不同类型
//               (   )   +    -   数值
enum obj_type { LP, RP, ADD, SUB, VAL };
struct obj
{
	obj(obj_type type, double val = 0) { t = type; v = val; }
	obj_type t;
	double v;
};

inline void skipws(string& exp, size_t& p)
{
	p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj>& so, double v)
{
	if (so.empty() || so.top().t == LP)
	{
		//空战或左括号
		so.push(obj(VAL, v));
	}
	else if (so.top().t == ADD || so.top().t == SUB)
	{
		//之前是运算符
		obj_type type = so.top().t;
		so.pop();
		//执行加减法
		if (type == ADD)
		{
			v += so.top().v;
		}
		else
		{
			v = so.top().v;
		}
		so.pop();
		so.push(obj(VAL, v)); //运算结果压栈
	}
	else
	{
		throw invalid_argument("缺少运算符");
	}
}


int main()
{
	stack<obj> so;
	string exp;
	size_t p = 0, q;
	double v;

	cout << "请输入表达式：" << endl;
	getline(cin, exp);

	while (p < exp.size())
	{
		skipws(exp, p); //跳过空格
		if (exp[p] == '(')
		{
			//左括号直接压栈
			so.push(obj(LP));
			p++;
		}
		else if (exp[p] == '+' || exp[p] == '-')
		{
			//新运算符
			if (so.empty() || so.top().t != VAL)
			{
				//空栈或之前不是运算数
				throw invalid_argument("缺少运算数");
			}
			if (exp[p] == '+')
			{
				//运算符压栈
				so.push(obj(ADD));
			}
			else
			{
				so.push(obj(SUB));
			}
			p++;
		}
		else if (exp[p] == ')')
		{
			//右括号
			p++;
			if (so.empty())
			{
				//之前无配对的左括号
				throw invalid_argument("未匹配右括号");
			}
			if (so.top().t == LP)
			{
				//一对括号之间无内容
				throw invalid_argument("空括号");
			}
			if (so.top().t == VAL)
			{
				//正确，括号内运算结果
				v = so.top().v;
				so.pop();
				if (so.empty() || so.top().t != LP)
				{
					throw invalid_argument("未匹配右括号");
				}
				so.pop();
				new_val(so, v); //与新运算数逻辑一致
			}
			else
			{
				//栈顶必定是运算符
				throw invalid_argument("缺少运算数");
			}
		}
		else
		{
			v = stod(exp.substr(p), &q);
			p += q;
			new_val(so, v);
		}
	}

	if (so.size() != 1 || so.top().t != VAL)
	{
		throw invalid_argument("非法表达式");
	}

	cout << so.top().v << endl;

	system("pause");
	return 0;
}

