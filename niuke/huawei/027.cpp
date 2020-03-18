//输入描述:
//	先输入字典中单词的个数，再输入n个单词作为字典单词。
//	输入一个单词，查找其在字典中兄弟单词的个数
//	再输入数字n
//
//输出描述:
//	根据输入，输出查找到的兄弟单词的个数
//
//示例1
//输入
//	3 abc bca cab abc 1
//输出
//	2
//	bca
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool brother_words(string word1, string word2)
{
	if (word1 == word2)
		return false;
	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());
	return word1 == word2;
}

int main()
{
	vector<string> dict;
	int n; // number of words in dict
	cin>>n;
	for (int i=0; i<n; i++) {
		string tmp;
		cin>>tmp;
		dict.push_back(tmp);
	}
	sort(dict.begin(), dict.end());

	string target_str;
	cin>>target_str;
	int target_num;
	cin>>target_num;

	vector<string> brother;
	for (int i=0; i<n; i++) {
		if (brother_words(target_str, dict[i])) {
			brother.push_back(dict[i]);
		}
	}
	cout<<brother.size()<<endl;
	if (brother.size()>target_num)
		cout<<brother[target_num-1]<<endl;

	return 0;
}
