#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int size = data.size();
		int firstPos = GetFirstOfK(data, k, 0, size-1);
		int lastPos = GetLastOfK(data, k, 0, size-1);
		if (firstPos!=-1 && lastPos!=-1)
			return lastPos-firstPos+1;
		return 0;
	}
private:
	// 递归方式二分查找到第一个K的位置
	int GetFirstOfK(vector<int> data, int k, int begin, int end)
	{
		if (begin>end) 
			return -1;

		int middleIndex = (begin+end)>>1;
		if (data[middleIndex] == k) {
			if ( (middleIndex!=0 && data[middleIndex-1]!=k) || middleIndex == 0) 
				return middleIndex;
			else 
				end = middleIndex-1;
		} else if (data[middleIndex] < k) {
			begin = middleIndex+1;
		} else {
			end  = middleIndex-1;
		}
		return GetFirstOfK(data, k, begin, end);
	}

	int GetLastOfK(vector<int> data, int k, int begin, int end)
	{
		// 循环方式二分查找到最后一个k的位置
		/*
		while (begin<=end) {
			int middleIndex = (begin+end)>>1;
			if (data[middleIndex] == k) {
				if ( (middleIndex!=end && data[middleIndex+1]!=k) || middleIndex == end) 
					return middleIndex;
				else 
					begin = middleIndex+1;
			} else if (data[middleIndex] < k) {
				begin = middleIndex+1;
			} else {
				end  = middleIndex-1;
			}
		}
		return -1;
		*/
		
		// 递归方式
		if (begin>end) 
			return -1;

		int size = data.size();
		int middleIndex = (begin+end)>>1;
		if (data[middleIndex] == k) {
			if ( (middleIndex!= (size-1) && data[middleIndex+1]!=k) || middleIndex == (size-1)) 
				return middleIndex;
			else 
				begin = middleIndex+1;
		} else if (data[middleIndex] < k) {
			begin = middleIndex+1;
		} else {
			end  = middleIndex-1;
		}
		return GetLastOfK(data, k, begin, end);
	}
};

int main()
{	
	int number[10] = {1,2,2,2,3,4,5,6,6,7};
	vector<int> data(number, number+10);
	for (auto it=data.begin(); it!=data.end(); it++)
		cout<<*it<<" ";
	cout<<endl;

	Solution s = Solution();
	cout<<"times of 2 : "<<s.GetNumberOfK(data, 2)<<endl;
	
	return 0;
}

