class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if(rows == 0) 
            return 0;
        int cols = obstacleGrid[0].size();
        
        vector<vector<long>> dp(rows, vector<long>(cols, 0));

        for (int x=0; x<rows; x++) {
            for (int y=0; y<cols; y++) {
                if (obstacleGrid[x][y] != 1) { 
                    dp[x][y] = 0;
                    if (x && y)
                        dp[x][y] = dp[x][y-1]+dp[x-1][y];
                    else if (x)
                        dp[x][y] = dp[x-1][y];
                    else if (y)
                        dp[x][y] = dp[x][y-1];
                    else 
                        dp[x][y] = 1;
                } else 
                    dp[x][y] = 0;
            }
        }
        return dp[rows-1][cols-1];
    }
};
