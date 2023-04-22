/*
* Bingo 访问网站，得到 HTTP 状态码，但他不知道什么含义，焦老师告诉他常见 HTTP 状态码：200（OK，请求已成
功），202（Accepted，服务器已接受请求，但尚未处理。）400（Bad Request，请求参数有误），403
（Forbidden，被禁止），404（Not Found，请求失败），500（Internal Server Error，服务器内部错误），502
（Bad Gateway，错误网关）。
*/
#include <iostream>
#include <string>
using namespace std;
void httpStatus()
{
	cout << "请输入状态码：";
	int status;
	cin >> status;
	switch (status)
	{
	case 200:
		cout << "OK，请求已成功" << endl;
		break;
	case 202:
		cout << "Accepted，服务器已接受请求，但尚未处理。" << endl;
		break;
	case 400:
		cout << "Bad Request，请求参数有误" << endl;
		break;
	case 403:
		cout << "Forbidden，被禁止" << endl;
		break;
	case 404:
		cout << "Not Found，请求失败" << endl;
		break;
	case 500:
		cout << "Internal Server Error，服务器内部错误" << endl;
		break;
	case 502:
		cout << "Bad Gateway，错误网关" << endl;
		break;
	default:
		cout << "error，未知状态码----" << endl;
		break;
	}
}
int main()
{
	httpStatus();

	system("pause");
	return 0;
}

