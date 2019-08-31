class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int countOutside(int m, int n, int k, int i, int j, vector<vector<vector<long> > >& dp) {
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
         
        dp[i][j][k] = 0;
        if (k == 0)
            return dp[i][j][k];
        for (int dir=0; dir<4; dir++) {
            int n_x = i+dx[dir];
            int n_y = j+dy[dir];
            if (n_x<0 || n_x>=m || n_y<0 || n_y>=n)
                dp[i][j][k]++;
            else
                dp[i][j][k]+=countOutside(m, n, k-1, n_x, n_y, dp)%1000000007;
        }
        dp[i][j][k] %= 1000000007;
        return dp[i][j][k];
    }
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<long> > >  dp(m, vector<vector<long> >(n, vector<long>(N+1, -1)));
        return countOutside(m, n, N, i, j, dp);
    }
};
