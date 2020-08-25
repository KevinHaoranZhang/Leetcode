class Solution {
public:
     bool isMatch(string s, string p) {
        int m = s.length() + 1;
        int n = p.length() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        int j=1;
        while(j<n && p[j-1] == '*'){
            dp[0][j++] = true;
        }
            
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?' )
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
