// 方法一
class Solution {
    void adjust(vector<int> & nums, int start, int end)
    {
        int dad = start;
        int son = dad * 2 + 1;
        while (son<=end) {
            if ((son+1) <= end && nums[son]<nums[son+1])
                son += 1;
            if (nums[dad] < nums[son]) {
                swap(nums[dad], nums[son]);
                dad = son;
                son = dad*2+1;
            } else {
                return ;
            }
        }
    }
    
    void heapify(vector<int> & nums) 
    {
        int len = nums.size();
        for (int i=len/2-1; i>=0; i--) {
            adjust(nums, i, len-1);
        }
        
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        heapify(nums);
        
        for (int i=len-1; i>=(len-k); i--) {
            swap(nums[0], nums[i]);
            adjust(nums, 0, i-1);
        }

        return nums[len-k];
    }
};

// 方法二
class Solution {
    int part(vector<int> & nums, int low, int high)
    {
        int priv = nums[low];
        while (low<high) {
            while (low<high && nums[high] >= priv)
                high--;
            nums[low] = nums[high];
            while (low<high && nums[low] <= priv)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = priv;
        return low;
    }
    
    int quick_select(vector<int> & nums, int k, int start, int end)
    {
   
        int priv = part(nums, start, end);
        if (priv == k)
            return nums[priv];
        
        if (priv > k) 
            return quick_select(nums, k, start, priv-1);
        else if (priv < k) 
            return quick_select(nums, k, priv+1, end);
        return -1;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return quick_select(nums, len-k, 0, len-1);
    }
};

