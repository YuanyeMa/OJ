# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
	int len = s.length();
	int i = 0;
	int j = i;
	while (i<len && j<=len) {
		if (s[j] == ' ' || s[j] == '\0') {
			reverseString(s, i, j);
			for (int k=i; k<j; k++)
				cout<<s[k]<<" ";
			cout<<endl; 
			i = j+1;
		}
		j++;
	}
	return s;
    }
private:
	void reverseString(string & s, int begin, int end) 
	{
		int size = end+1-begin;
		for (int i=begin; i<begin+size/2; i++) {
			swap(s[i], s[end-(i-begin)-1]);
		}
	}
};

int main()
{
	string str="Let's take LeetCode contest";
	Solution s;
	cout<<s.reverseWords(str)<<endl;

	return 0;
}

