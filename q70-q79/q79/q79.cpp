class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (word[0] == board[i][j] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }
        
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        
        char old = board[row][col];
        board[row][col] = '$';
        
        // all branches
        for (const auto& dir : dirs) {
            if (dfs(board, word, row + dir[0], col + dir[1], index + 1)) {
                board[row][col] = old;
                return true;
            }
        }
        
        board[row][col] = old;
        return false;
    }
};
