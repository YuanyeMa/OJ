/*
判断一个整数是否是回文数
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	if (x<0) 
		return false;
        vector<int> s;
	while(x) {
		char a = (x%10)+'0';
		s.push_back(a);
		x/=10;
	}
	int i = 0;
	int j = s.size()-1;
	while (i<j) {
		if (s[i++] != s[j--])
			return false;
	}
	return true;
    }
};

int main()
{
	Solution s;
	int x = -121;
	bool flag = s.isPalindrome(x);	
	if (flag)
		cout<<"yes"<<endl;
	else 
		cout<<"no"<<endl;

	return 0;
}

