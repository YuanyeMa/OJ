#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<vector<int> > result;
	void prem(vector<int>& num, int p, int q)
	{
		if (p == q)
			result.push_back(num);

		for (int i=p; i<=q; i++) {
			swap(num[p], num[i]);
			prem(num, p+1, q);
			swap(num[p], num[i]);
		}
	}
public:
	vector<vector<int> > permute(vector<int>& nums) {
		int len = nums.size();
		prem(nums, 0, len-1);
		sort(result.begin(), result.end());
		return result;
	}
};

int main()
{
	int nu[3] = {1,2,3};
	vector<int> nums(nu, nu+3);
	Solution s;
	vector<vector<int> > r = s.permute(nums);

	for (auto it=r.begin(); it!=r.end(); it++) {
		for (int i=0; i<(*it).size(); i++)
			cout<<(*it)[i]<<" ";
		cout<<endl;
	}

	return 0;
}
