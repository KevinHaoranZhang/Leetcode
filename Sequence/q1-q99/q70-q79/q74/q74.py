class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0:
            return False
        if len(matrix[0]) == 0:
            return False
        left, right, middle = 0, len(matrix) - 1, 0
        while left <= right:
            middle = (left + right) // 2
            if matrix[middle][0] == target:
                return True
            if matrix[middle][0] < target:
                left = middle + 1
            elif matrix[middle][0] > target:
                right = middle - 1
        row_index = 0
        if matrix[middle][0] < target:
            row_index = middle
        else:
            if middle - 1 >= 0:
                row_index = middle - 1
            else:
                row_index = 0 
        left, right = 0, len(matrix[0]) - 1
        while left <= right:
            middle = (left + right) // 2
            if matrix[row_index][middle] == target:
                return True
            if matrix[row_index][middle] < target:
                left = middle + 1
            elif matrix[row_index][middle] > target:
                right = middle - 1
        return False
        
