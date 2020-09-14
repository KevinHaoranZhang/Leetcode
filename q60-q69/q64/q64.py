class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp_table = [[0 for _ in range(n)] for y in range(m)]
        dp_table[0][0] = grid[0][0]
        for i in range(1, m):
            dp_table[i][0] = dp_table[i-1][0] + grid[i][0]
        for i in range(1, n):
            dp_table[0][i] = dp_table[0][i-1] + grid[0][i]
        for i in range(1, m):
            for j in range(1, n):
                dp_table[i][j] = min(dp_table[i-1][j], dp_table[i][j-1]) + grid[i][j]
        return dp_table[m-1][n-1]
        
