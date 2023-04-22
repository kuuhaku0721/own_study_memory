/*
ͳ���ַ����в�ͬ�ַ����ֵ�Ƶ�� �Ϸ��ַ�ΪA~Z��0~9
*/
#include <iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


void count_char()
{
    cout << "请输入一个字符串（包含A-Z和0-9）" << endl;
    string str;
    cin >> str;

    set<char> s; //set去重
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (*it >= 'A' && *it <= 'Z')
        {
            s.insert(*it);
        }
        else if (*it >= '0' && *it <= '9')
        {
            s.insert(*it);
        }
        else
        {
            continue;
        }
    }
    map<char, int> m; //key为字符，value为出现次数
    for (auto it = s.begin(); it != s.end(); it++)
    {
        int cnt = count(str.begin(), str.end(), *it);
        m.insert(make_pair(*it, cnt));
    }
    cout << "每个字符出现次数：" << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "-->" << it->second << endl;
    }
}


int main()
{
    count_char();

    system("pause");
    return 0;
}
