class Solution:
    def maxArea(self, height: List[int]) -> int:
        solution = 0
        current_area = 0
        left = 0
        right = len(height)-1
        while (left != right):
            # current_area = height[left]*(right-left) if height[left] < height[right] else height[right]*(right-left)
            # solution = current_area if current_area > solution else solution
            if height[left] < height[right]:
                current_area = height[left]*(right-left)
            else:
                current_area = height[right]*(right-left)
            if current_area > solution:
                solution = current_area
            if(height[left] < height[right]):
                left += 1
            else:
                right -= 1
        return solution
        
