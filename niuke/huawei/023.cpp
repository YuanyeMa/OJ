//题目描述
//实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
//注意每个输入文件有多组输入，即多个字符串用回车隔开
//输入描述:
//字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。
//
//输出描述:
//删除字符串中出现次数最少的字符后的字符串。
//
//示例1
//输入
//abcdd
//输出
//dd

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string str;
	while(cin>>str) {
		/*
		map<char, int> table;
		for (auto it=str.begin(); it!=str.end(); it++) {
			if (table.find(*it) != str.end()) {
				table[*it]++;
			} else {
				table[*it] = 1;
			}
		}
		int min_c = table.size();
		for (auto it=table.begin(); it!=table.end(); it++) {
			if ((*it).second < min_c)
				min_c = (*it).second;
		}
		*/
		int map_table[26] = {0};
		int size = str.size();
		for (int i=0; i<size; i++) {
			map_table[str[i]-'a']++;	
		}
		int min_c = 25;
		for (int i=0; i<26; i++) {
			if (min_c>map_table[i] && map_table[i]!=0) {
				min_c = map_table[i];
			}
		}
		for (auto it=str.begin(); it!=str.end(); ) {
			if (map_table[(*it)-'a'] == min_c) {
				str.erase(it);
			} else {
				it++;
			}
		}
		cout<<str<<endl;
	}
	return 0;
}
