class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> copy(size,vector<int> (size));
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                copy[i][j] = matrix[size - 1 - j][i];
            }
        }
        matrix = copy;
    }
};
