class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        dp = [1 for index in range(0, len(s) + 1)]
        for i in range(1, len(s)):
            if s[i] == '0':
                if s[i-1] != '1' and s[i-1] != '2':
                    return 0
                dp[i+1] = dp[i-1]
                continue
            if s[i-1] == '1' or s[i-1] == '2' and s[i] < '7':
                dp[i+1] = dp[i] + dp[i-1]
            else:
                dp[i+1] = dp[i]
        return dp[len(s)]
