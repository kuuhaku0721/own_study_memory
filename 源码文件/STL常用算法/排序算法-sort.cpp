#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* sort(begin, end, 谓词);  
* 谓词不填默认从小到大，填了就按谓词的规矩
*/
void printVector(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	cout << "排序前：";
	printVector(v);
	cout << "排序后：";
	sort(v.begin(), v.end());
	printVector(v);
	cout << "降序排序后：";
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
	
}

int main()
{

	test01();



	system("pause");
	return 0;
}

