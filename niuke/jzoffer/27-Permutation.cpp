#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
        	if (str.length() == 0) return result;
		PermutationCore(str, 0);
		
		sort(result.begin(), result.end());
		return result;	
	}
private:
	vector<string> result;
	void PermutationCore(string str, int begin) {
		if (str.length() == begin) {
			result.push_back(str);
			return;
		}
		for (int i = begin; i < str.length(); i++) {
			if ( i != begin && str[i] == str[begin]) continue;
			
			swap(str[begin], str[i]);
			
			PermutationCore(str, begin+1);
		}
	}
};

int main()
{
	string str = "abcd";
	Solution s = Solution();
	vector<string> result = s.Permutation(str);

	for (auto it = result.begin(); it != result.end(); it++)
		cout<<*it<<endl;
	
	return 0;
}

