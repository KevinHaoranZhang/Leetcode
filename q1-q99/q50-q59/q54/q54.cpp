class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
        if (matrix.empty())
            return solution;
        int row_bound = matrix.size();
        int col_bound = matrix[0].size();
        int row_index = 0, col_index = 0, dir_index = 0;
        // clockwise, E -> S -> W -> N
        int row_direction[] = {0, 1, 0, -1};
        int col_direction[] = {1, 0, -1, 0};
        vector<vector<bool>> seen(row_bound, vector<bool>(col_bound, false));
        for (int i = 0; i < row_bound * col_bound; i++){
            solution.push_back(matrix[row_index][col_index]);
            seen[row_index][col_index] = true;
            int next_row_index = row_index + row_direction[dir_index];
            int next_col_index = col_index + col_direction[dir_index];
            if (0 <= next_row_index && next_row_index < row_bound &&
                0 <= next_col_index && next_col_index < col_bound && 
                !seen[next_row_index][next_col_index]){
                row_index = next_row_index;
                col_index = next_col_index;
            } else {
                dir_index = (dir_index + 1) % 4;
                row_index += row_direction[dir_index];
                col_index += col_direction[dir_index];
            }
        }
        return solution;
    }
};
