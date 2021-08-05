#include <unordered_map>
#include <iostream>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            std::unordered_map <char, int> row;
            std::unordered_map <char, int> col;
            std::unordered_map <char, int> cube;
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.' && row.find(board[i][j]) != row.end())
                    return false;
                if (board[j][i] != '.' && col.find(board[j][i]) != col.end())
                    return false;
                int rowIndex = 3* (i / 3);
                int colIndex = 3 * (i % 3);
                if (board[rowIndex + j/3][colIndex + j%3] != '.' && cube.find(board[rowIndex + j/3][colIndex + j%3]) != cube.end())
                    return false;
                if (board[i][j] != '.')
                    row.insert(std::make_pair(board[i][j], 0));
                if (board[j][i] != '.')
                    col.insert(std::make_pair(board[j][i], 0));
                if (board[rowIndex + j/3][colIndex + j%3] != '.')
                    cube.insert(std::make_pair(board[rowIndex + j/3][colIndex + j%3], 0));
            }
        }
        return true;
    }
};
