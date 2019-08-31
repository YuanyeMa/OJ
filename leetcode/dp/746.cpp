// 从i个台阶只能跳到i+1或者i+2去， 第i个台阶往上走的cost最小为 cost[i]+min(cost[i+11], cost[i+2])
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 0) 
            return 0;
        else if (size == 1)
            return cost[0];
        else if (size == 2)
            return min(cost[0], cost[1]);
        
        vector<int> dp(size, 0);
        dp[size-1] = cost[size-1];
        dp[size-2] = cost[size-2];
        for (int i=size-3; i>=0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 0) 
            return 0;
        else if (size == 1)
            return cost[0];
        else if (size == 2)
            return min(cost[0], cost[1]);
        
        vector<int> dp(size, 0);
        dp[0] = cost[0]; 
        dp[1] = min(cost[0], cost[1]);
        for (int i=2; i<size; i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[size-1];
    }
};
