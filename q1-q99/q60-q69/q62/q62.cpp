class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp_table(m, vector<int>(n, 0));
        int i = 0, j = 0;
        for (i = 0; i < m; i++){
            dp_table[i][0] = 1;
        }
        for (j = 0; j < n; j++){
            dp_table[0][j] = 1;
        }
        for (i = 1; i < m; i++){
            for (j = 1; j < n; j++){
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
            }
        }
        return dp_table[m-1][n-1];
    }
};
