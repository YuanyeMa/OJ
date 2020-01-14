#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
	string res;
	int len = str.size();
	cout<<len<<endl;
	if (len == 0)
		return res;
	int begin = len-1;
	int end = len;

	while (1) {
		while (str[begin] != ' ' &&  begin>=0) {
			begin--;
		}

		for (int i=begin+1; i<end; i++) {
			res.push_back(str[i]);
		}
		if (begin < 0) {
			res.push_back('\0');
			return res;
		}

		res.push_back(' ');
		end = begin;
		begin = end-1;
	}
    }
};

int main()
{
	string s = "I am a student."; //"student. a am I";
	Solution ss;	
	cout<<ss.ReverseSentence(s)<<endl;

	return 0;
}
