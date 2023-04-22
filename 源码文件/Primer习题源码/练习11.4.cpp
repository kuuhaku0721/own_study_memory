/*
* 忽略大小写和标点的单词计数程序
*/
#include <iostream>
#include <string>
#include<map>
#include<algorithm>
using namespace std;

string& trans(string& s)
{
	for (int p = 0; p < s.size(); p++)
	{
		if (s[p] >= 'A' && s[p] <= 'Z')
		{
			s[p] -= ('A' - 'a');
		}
		else if (s[p] == ',' || s[p] == '.')
		{
			s.erase(p, 1);
		}
	}
	return s;
}

int main()
{
	map<string, size_t> word_count; //从string到count的映射
	string word[10] = { "cpp","java","Phython","qt","springboot","mybaits","javaweb","ue","STL","cpp" };
	for (int i = 0; i < 10; i++)
	{
		++word_count[trans(word[i])]; //这个单词的出现次数+1
	}
	for (const auto& w : word_count) //对map中的每个元素
	{
		//打印结果
		cout << w.first << "出现了" << w.second << "次" << endl;
	}


	system("pause");
	return 0;
}

