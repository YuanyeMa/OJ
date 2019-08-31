#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dg(string s, int begin, vector<string> & result)
{
	int len = s.length();
	if (begin == len-1) {
		result.push_back(s);
		return ;
	}
	for (int i=begin; i<len; i++) {
		swap(s[begin], s[i]);
		dg(s, begin+1, result);
		swap(s[begin], s[i]);
	}
}

vector<string> qpl(string s)
{
	vector<string> result;
	dg(s, 0, result);	
	sort(result.begin(), result.end());
	return result;
}

int main()
{
	string str;
	cin>>str;
	vector<string> res = qpl(str);
	for (auto it : res)
		cout<<it<<endl;
	
	return 0;
}

