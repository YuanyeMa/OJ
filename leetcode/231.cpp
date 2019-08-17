/*
	给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
	if (n <= 0)
		return false;
	return ((n&(n-1)) == 0);
    }
};

int main()
{
	Solution s;
	if(s.isPowerOfTwo(1))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	if(s.isPowerOfTwo(16))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}

