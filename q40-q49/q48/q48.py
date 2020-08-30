import copy
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        backup = copy.deepcopy(matrix)
        size = len(matrix)
        for i in range(0, size):
            for j in range(0, size):
                matrix[i][j] = backup[size - j - 1][i]
        
