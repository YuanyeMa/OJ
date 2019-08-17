/*
	把一个整数反转
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
	
	int ans = 0;
	while (x) {
		int pop = x%10;
		x/=10;

		if (ans > INT_MAX/10 || (ans == INT_MAX/10 && pop>7) ) 
			return 0;
		if (ans < -INT_MAX/10 || (ans == -INT_MAX/10 && pop<-8) ) 
			return 0;
		ans= ans * 10 + pop;
	}
	return ans;
    }
};

int main()
{
	cout<<INT_MAX<<endl;
	int x1 = 123;
	int x2 = -123;
	int x3 = 120;
	int x4 = 1534236469;
	Solution s;
	cout<<s.reverse(x1)<<endl;
	cout<<s.reverse(x2)<<endl;
	cout<<s.reverse(x3)<<endl;
	cout<<s.reverse(x4)<<endl;
	
	return 0;
}

