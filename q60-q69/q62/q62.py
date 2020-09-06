class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp_table = [[0 for i in range(n)] for j in range(m)]
        for i in range(0, m):
            dp_table[i][0] = 1
        for j in range(0, n):
            dp_table[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1]
        return dp_table[m-1][n-1]
