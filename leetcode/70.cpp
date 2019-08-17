/*
	爬楼梯
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	int i = 1;
	int j = 1; 
	int ans = 0;
	for (int k=2; k<=n; k++) {
		ans = i+j;
		i = j;
		j = ans;
	} 
	return ans;      
    }
};

int main()
{
	Solution s;
	for (int i=0; i<10; i++)
		cout<<s.climbStairs(i)<<endl;
}
