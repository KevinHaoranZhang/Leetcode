class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums) - 1
        found = False
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] == target:
                found = True
                break
            if nums[middle] <= target:
                left = middle + 1
            else:
                right = middle - 1
        if (found):
            left = middle
            right = middle
            while left - 1 >= 0 and nums[left - 1] == target:
                left = left -1
            while right + 1 <= len(nums) -1 and nums[right + 1] == target:
                right = right + 1
            return [left, right]
        return [-1, -1]
