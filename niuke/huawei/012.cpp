/*
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：

输入描述:
	输入N个字符
输出描述:
	输出该字符串反转后的字符串
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin>>str;
	for (auto it=str.end()-1; it!=str.begin()-1; it--)
		cout<<*it;
	cout<<endl;
	return 0;
}
