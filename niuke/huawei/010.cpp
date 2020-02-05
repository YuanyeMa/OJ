/*
题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。

输入描述:
	输入N个字符，字符在ACSII码范围内。
输出描述:
	输出范围在(0~127)字符的个数。
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;	
	cin>>str;
	
	int bitmap[128] = {0};
	int result = 0;
	for (auto it=str.begin();  it!=str.end(); it++) {
		if (bitmap[*it] == 0) {
			bitmap[*it] = 1;
			result++;
		}			
	}
	cout<<result<<endl;
	return 0;
}
