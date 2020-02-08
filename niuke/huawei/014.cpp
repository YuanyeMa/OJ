/*
题目描述
给定n个字符串，请对n个字符串按照字典序排列。
输入描述:
	输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述:
	数据输出n行，输出结果为按照字典序排列的字符串。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<string> strs;
	while(n--) {
		string str;
		cin>>str;
		strs.push_back(str);
	}
	
	for (auto it=strs.begin(); it!=strs.end(); it++) {
		for (auto iit=it; iit!=strs.end(); iit++) {
			if ( (*it)>(*iit) ) {
				auto tmp = *it;
				*it = *iit;
				*iit = tmp;
			}
		}
	}	
	
	for (auto it=strs.begin(); it!=strs.end(); it++)
		cout<<*it<<endl;

	
	return 0;
}

