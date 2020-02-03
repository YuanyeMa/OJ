/*
 * 题目描述
 *
 * 写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写
 *
 * 第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。
 *
 * 输出输入字符串中含有该字符的个
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool is_tar(char a,  char b)
{
	if (a==b || abs(a-b)==32)
		return true;	
	else 
		return false;
}

int main()
{	
	string str;
	char tar;
	getline(cin, str);
	cin>>tar;

	int result = 0;
	for (auto it=str.begin(); it!=str.end(); it++) {
		if (is_tar(*it, tar))
			result++;	
	}

	cout<<result<<endl;	
	return 0;
}

