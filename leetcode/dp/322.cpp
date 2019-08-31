class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount+1,  INT_MAX-1);
        dp[0] = 0;
        for (int i=0; i<len; i++) {
            for (int j=coins[i];j <= amount; j++) {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        if ( dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};

