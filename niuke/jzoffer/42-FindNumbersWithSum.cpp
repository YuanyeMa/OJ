#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
	vector<int> res;
	int len = array.size();
	if (len < 2)
		return res;
  	int begin = 0;  
	int end = len-1;
	
	while (begin != end) {
		if (array[begin]+array[end] > sum) {
			end--;
		} else if (array[begin]+array[end] == sum) {
			res.push_back(array[begin]);
			res.push_back(array[end]);
			break;
		} else {
			begin++;
		}
	}
	return res;
    }
};

int main()
{
	int array[] = {1, 2, 3, 7, 9, 10};
	vector<int> arr(array, array+6);
	Solution s;
	vector<int> res = s.FindNumbersWithSum(arr, 10);
	for(auto it=res.begin(); it!=res.end(); it++)
		cout<<*it<<endl;
	return 0;
}

