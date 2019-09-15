#include <iostream>

using namespace std;

void adjust_down(int * nums, int start, int end)
{
	int dad = start;
	int son = dad*2+1;
	while (son <= end) {
		if (son+1 <= end &&  nums[son]<=nums[son+1])
			son++;
		if (nums[dad] > nums[son])
			return ;
		else {
			swap(nums[dad], nums[son]);
			dad = son;
			son = dad*2+1;
		}
	}
}

void build_max_heap(int * nums, int len)
{
	for (int i=len/2-1; i>=0; i--) {
		adjust_down(nums, i, len-1);
	}
}

void heap_sort(int * nums, int len)
{
	build_max_heap(nums, len);
	for (int i=len-1; i>=0; i--) {
		swap(nums[0], nums[i]);
		adjust_down(nums, 0, i-1);
	}	
}

int main()
{
	int nums[] = {7,6,5,4,3,2,1,1,0};
	//int nums[] = {0,0,1,1,2,3,4,5,6,7};

	heap_sort(nums, sizeof(nums)/sizeof(int));

	for (int i=0; i<sizeof(nums)/sizeof(int); i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	return 0;
}
