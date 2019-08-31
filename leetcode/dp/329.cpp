class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int rows, cols;
    
    int searchPath(int x, int y, vector<vector<int>> & matrix, vector<vector<int>> & dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        
        dp[x][y] = 1;
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx>=0 && ny>=0 && nx<rows && ny<cols && matrix[nx][ny]>matrix[x][y]) {
                dp[x][y] = max(dp[x][y], searchPath(nx, ny, matrix, dp)+1);
            } 
        }
        return dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows == 0)
            return 0;
        cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        
        int maxx = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                dp[i][j] = searchPath(i, j, matrix, dp);
                if (dp[i][j] > maxx)
                    maxx = dp[i][j];
                
            }
        }
        return maxx;
    }
};
