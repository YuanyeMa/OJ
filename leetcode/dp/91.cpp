class Solution {
public:
    int numDecodings(string s) {
        s = '0'+s;
        int len = s.length();
        
        vector<int> dp(len);
        dp[0] = 1;
        
        for (int i=1; i<len; i++) {
            dp[i] = 0;
            if (s[i] != '0')
                dp[i] += dp[i-1];
            if (i>1) {
                int tmp = (s[i-1]-'0')*10+(s[i]-'0');
                if (tmp>=10 && tmp<=26) 
                    dp[i] += dp[i-2];    
            }
        }
        return dp[len-1];
    }
};
