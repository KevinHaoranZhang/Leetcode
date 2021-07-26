class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        row_bound, col_bound = len(matrix), len(matrix[0])
        seen = [[False] * col_bound for _ in matrix]
        solution = []
        row_dir = [0, 1, 0, -1]
        col_dir = [1, 0, -1, 0]
        row_index = col_index = dir_index = 0
        for i in range(row_bound * col_bound):
            solution.append(matrix[row_index][col_index])
            seen[row_index][col_index] = True
            next_row_index, next_col_index = row_index + row_dir[dir_index], col_index + col_dir[dir_index]
            if 0 <= next_row_index and next_row_index < row_bound and 0 <= next_col_index and next_col_index < col_bound and not seen[next_row_index][next_col_index]:
                row_index, col_index = next_row_index, next_col_index
            else:
                dir_index = (dir_index + 1) % 4
                row_index, col_index = row_index + row_dir[dir_index], col_index + col_dir[dir_index]
        return solution
