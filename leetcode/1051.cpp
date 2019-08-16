class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> af_sort = heights;
        sort(af_sort.begin(), af_sort.end());
        
        int len = heights.size();
        int cnt = 0;
        for (int i=0; i<len; i++) {
            if (af_sort[i] != heights[i])
                cnt++;
        }
        return cnt;
    }
};

 
