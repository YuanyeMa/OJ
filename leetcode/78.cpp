// 二进制进位法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > result;
        int num_s = 1<<len;
        for (int j=0; j<num_s; j++) {
            vector<int> res;
            for (int i=0; i<len; i++) {
                if (j & 1<<i)
                    res.push_back(nums[i]);
            }
            result.push_back(res);
        }
        return result;
    }
};
// 回溯法
class Solution {
    void dfs(const vector<int>& nums, int pos, int len, vector<int>& cur, vector<vector<int>> & res) 
    {
        if (len == cur.size()) {
            res.push_back(cur);
            return ;
        }
        
        for (int i=pos; i<nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, i+1, len, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > result;
        vector<int> cur;
        for (int i=0; i<=len; i++) {
            dfs(nums, 0, i, cur, result);
        }
        return result;
    }
};
