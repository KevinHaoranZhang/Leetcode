class Solution {
public:
    int solution;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        solution = 0;
        n_queen(0, n);
        return solution;
    }
    void n_queen(int row, int n){
        if (row == n){
            solution++;
            return;
        }
        // iterate over each column
        for (int x = 0; x < n; x++){
            if (col[x] || diag1[row + x] || diag2[x - row + n - 1])
                continue;
            col[x] = true;
            diag1[row + x] = true;
            diag2[x - row + n - 1] = true;
            n_queen(row + 1, n);
            col[x] = false;
            diag1[row + x] = false;
            diag2[x - row + n - 1] = false;
        }
    } 
};
