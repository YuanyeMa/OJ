#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) 
    {
	int len = numbers.size();
	if (len == 0)
		return false;
        int zeros = 0;
	int gaps = 0;
	int base = 0;

	sort(numbers.begin(), numbers.end());
	for (int i=0; i<len; i++) {
		if (numbers[i] == 0)
			zeros++;
		else {
			if (base == 0)
				base = numbers[i];
			else {
				gaps += numbers[i]-base-1;
				base = numbers[i];
				if (gaps<0) // 有重复的牌
					return false;
			}
		}
	}
	return gaps<=zeros?true:false;
    }
};

int main()
{	
	int arr[] = {1,3,2,5,4};
	vector<int> nums(arr, arr+5);

	Solution s;
	if (s.IsContinuous(nums))
		cout<<"yes"<<endl;
	else 
		cout<<"no"<<endl;

	return 0;
}

