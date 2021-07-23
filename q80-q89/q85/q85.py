class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        index_stack = []
        left_index = [0 for i in range(0, len(heights))]
        for i in range(0, len(heights)):
            while index_stack != [] and heights[i] <= heights[index_stack[-1]]:
                index_stack.pop()
            if index_stack != []:
                left_index[i] = index_stack[-1] + 1
            else:
                left_index[i] = 0
            index_stack.append(i)
            
        while index_stack != []:
            index_stack.pop()
            
        right_index = [0 for i in range(0, len(heights))]
        for i in range(len(heights) - 1, -1, -1):
            while index_stack != [] and heights[i] <= heights[index_stack[-1]]:
                index_stack.pop()
            if index_stack != []:
                right_index[i] = index_stack[-1] - 1
            else:
                right_index[i] = len(heights) - 1
            index_stack.append(i)
            
        max_area = 0
        for i in range(0, len(heights)):
            max_area = max(max_area, heights[i] * (right_index[i] - left_index[i] + 1))
        return max_area
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        histogram = [0 for i in range(0, len(matrix[0]))]
        max_area = 0
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[0])):
                if matrix[i][j] == '0':
                    histogram[j] = 0
                else:
                    histogram[j] += 1
            cur_histo_area = self.largestRectangleArea(histogram)
            max_area = max(max_area, cur_histo_area)
        return max_area
