#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
	int len = str.size();
	if (len==0)
		return str;

	string res(str);
	for (int i=0; i<len; i++) {
		res[i] = str[(i+n)%len];
	}
	return res;
    }
};

int main()
{
	string str = "abcXYZdef";
	Solution s;
	string res = s.LeftRotateString(str, 3);
	cout<<res<<endl;

	return 0;
}

