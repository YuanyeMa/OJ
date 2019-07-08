#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
//    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
// 	vector<int> result;
//	if (input.empty() || k > input.size()) return result;
//	sort(input.begin(), input.end());
//	for (int i = 0; i < k; i++)
//		result.push_back(input[i]);
//	return result;       
//  }
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		return sort_heap(input);

		vector<int> result;
		int size = input.size();

		for (int i = 0; i<size; i++) {
			// 先在结果vector中插入K个元素
			if (result.size() < k) {
				result.push_back(input[i]);
				continue;
			}
			// 建堆
			sort_heap(result);
			// 和堆顶元素对比
			if ( input[i] < result[0])	
				swap(input[i], result);
		}
		return result;
	}
private:
	//建大顶堆
	int sort_heap(vector<int> &numbers) {
		int size = numbers.size();
		int parent = size/2-1;
		
		for (int j=parent; j>0; j--) {
			int child = parent*2+1;
			if (child < size && numbers[child] > numbers[parent]) 
				swap(numbers[child], numbers[parent]);
			child++;
			if (child < size && numbers[child] > numbers[parent]) 
				swap(numbers[child], numbers[parent]);
		}		
		return number[0];
	}
};

int main()
{
	int nums[] = {4,5,1,6,2,7,3,8};
	vector<int> input(nums, nums+8);

	for (auto it = input.begin(); it != input.end(); it++)
		cout<<" "<<*it;
	cout<<endl;
	
	Solution s;
	vector<int> result = s.GetLeastNumbers_Solution(input, 2);
	for (auto it = result.begin(); it != result.end(); it++)
		cout<<*it<<endl;

	return 0;
}

