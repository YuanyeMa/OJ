# include <iostream>
# include <vector>
# include <cstdio>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
  	int len = s.size();
	cout<<len<<endl;
	for (int i=0, j=len-1; i<j; i++,j--) {
		swap(s[i], s[j]);
	}      
    }
};

int main()
{
	char a[]= "hello";
	printf("%s\n", a);
	vector<char> str(a, a+5);
	for(int i=0; i<str.size(); i++)
		cout<<str[i]<<" ";
	cout<<endl;

	Solution s;
	s.reverseString(str);

	for(int i=0; i<str.size(); i++)
		cout<<str[i]<<" ";
	cout<<endl;

	return 0;
}
