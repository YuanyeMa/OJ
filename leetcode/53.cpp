#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  	int len = nums.size();
	// 动态规划解法
	// vector<int> f(len);
	// f[0] = nums[0];
	// for (int i=1; i<len; i++)
	//	f[i] = max(f[i-1]+nums[i], nums[i]);
	// return max_element(f.begin(), f.end());

	// 因为只和f[i]的前一项有关，因此可以将空间复杂度优化为O(1)
	int f = nums[0];
	int ans = nums[0];
	for (int i=1; i<len; i++) {
		f = max(f+nums[i], nums[i]);
		if (f > ans)
			ans = f; 
	}
	return ans;
    }
};

int main()
{

}
