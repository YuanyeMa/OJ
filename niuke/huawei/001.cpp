/*
 * 计算字符串最后一个单词的长度，单词以空格隔开
 * */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int len = s.size();
	int result = -1;
	auto it = s.end();
	for (; it!=s.begin(); it--) {
		if (*it == ' ')
			break;
		else {
			result++;
		}
			
	}
	if (it == s.begin())
		result++;
	cout<<result<<endl;
	return 0;
}
