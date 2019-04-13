#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	int len = rotateArray.size();
		if (!len) return 0;
		
		int left = 0; 
		int right = len-1;
		int mid = 0;
			
		while(rotateArray[left] >= rotateArray[right]){
			if (right-left == 1) {
				mid = right;
				break;
			}
			mid = (left+right)/2;
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[right])
					return min(rotateArray, left, right);
			if (rotateArray[mid] >= rotateArray[left]) left = mid;
			else right = mid;
		}
		return rotateArray[mid];
    }

private:
	int min(vector<int> rotateArray, int left, int right){
		int m = rotateArray[left];
		for (int i=left+1; i<right; i++){
			if (rotateArray[i] < m)
					m = rotateArray[i];
		}
		return m;
	}
};

int main()
{		
	int num[4] = {1, 0, 1, 1}; 
	int num1[5] = {3, 4, 5, 1, 2};

	vector<int> vec1(num, num+4);
	vector<int> vec2(num1, num1+5);

	Solution s;
	cout<<s.minNumberInRotateArray(vec1)<<endl;
	cout<<s.minNumberInRotateArray(vec2)<<endl;

	return 0;
}
