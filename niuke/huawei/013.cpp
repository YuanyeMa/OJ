/*
题目描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

接口说明
	public String reverse(String sentence);

输入描述:
	将一个英文语句以单词为单位逆序排放。

输出描述:
	得到逆序的句子
*/

#include <iostream>
#include <string>

using namespace std;

string reverse(string str)
{
	int len = str.size();
	if (len == 0)
		return str;

	string result;	
	int end = len;
	for (int i=len; i>0; i--) {
		if (str[i] == ' ') {
			string tmp(str, i+1, end-i);
			if (end == len)
				tmp+=" ";
			result+=(tmp);
			end = i;
		}
	}
	string tmp(str, 0, end);
	return result+tmp;
}

int main()
{
	string str;
	getline(cin, str);

	cout<<reverse(str)<<endl;

	return 0;
}
