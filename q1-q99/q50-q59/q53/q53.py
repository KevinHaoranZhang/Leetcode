class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        current_max = nums[0]
        solution = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > current_max + nums[i]:
                current_max = nums[i]
            else:
                current_max = current_max + nums[i]
            if current_max > solution:
                solution = current_max
        return solution
