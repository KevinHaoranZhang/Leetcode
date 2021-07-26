class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        dp = [[False for i in range(0, len(s2) + 1)] for j in range(0, len(s1) + 1)]
        size1 = len(s1)
        size2 = len(s2)
        size3 = len(s3)
        if size1 + size2 != size3:
            return False
        dp[0][0] = True
        for i in range(0, len(s1) + 1):
            for j in range(0, len(s2) + 1):
                if i > 0:
                    dp[i][j] |= (dp[i-1][j] and s1[i-1] == s3[i+j-1])
                if j > 0:
                    dp[i][j] |= (dp[i][j-1] and s2[j-1] == s3[i+j-1])
        return dp[size1][size2]
