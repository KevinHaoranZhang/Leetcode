class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right, middle = 0, len(nums) - 1, 0
        while left <= right:
            middle = (left + right) // 2
            if nums[left] == target or nums[right] == target or nums[middle] == target:
                return True
            if nums[middle] < nums[right]:
                if nums[middle] < target and target < nums[right]:
                    left = middle + 1
                else:
                    right = middle - 1
            elif nums[middle] > nums[left]:
                if nums[middle] > target and nums[left] < target:
                    right = middle - 1
                else:
                    left = middle + 1
            else:
                right -= 1
        return False
