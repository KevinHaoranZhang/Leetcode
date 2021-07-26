class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // two pointers do not consider all possible solutions,
        // setting any pointers of s1, s2 would leave the other as a possible solution
        vector<vector<int>> dp (s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int size1 = s1. size(), size2 = s2.size(), size3 = s3.size(); 
        if (size1 + size2 != size3) return false;
        dp[0][0] = 1;
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i > 0) {
                    dp[i][j] |= (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[size1][size2];
    }
};
