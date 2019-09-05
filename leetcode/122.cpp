class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0;
        int len = prices.size();
        if (len<2)
            return maxx;
        for (int i=1; i<len; i++) {
            if (prices[i] > prices[i-1])
                maxx += prices[i]-prices[i-1];
        }
        return maxx;
    }
};
