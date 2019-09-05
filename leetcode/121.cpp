class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        int maxx = 0;  // 最大利润
        int f = prices[0]; // 前i天中的最低价
        for (int i=1; i<len; i++) {
            f = min(f, prices[i]);
            int dif = prices[i]-f;
            
            if (dif > maxx)
                maxx = dif;
        }
        return maxx;
    }
};
