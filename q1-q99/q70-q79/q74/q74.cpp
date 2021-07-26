class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0){
            return false;
        }
        int left = 0, right = row - 1, middle = 0;
        int row_index = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (matrix[middle][0] == target) {
                return true;
            }
             if (matrix[middle][0] > target) {
                right = middle - 1;
            } else if (matrix[middle][0] < target) {
                left = middle + 1;
            }
        }
        if (matrix[middle][0] < target)
            row_index = middle;
        else
            row_index = middle - 1 >= 0 ? middle - 1 : 0;
        left = 0;
        right = col - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[row_index][middle] == target) {
                return true;
            }
            if (matrix[row_index][middle] < target) {
                left = middle + 1;
            } else if (matrix[row_index][middle] > target) {
                right = middle - 1;
            }
        }
        return false;
    }
};
