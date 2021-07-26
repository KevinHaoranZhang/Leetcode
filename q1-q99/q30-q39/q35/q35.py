class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        middle = 0 
        while left < right:
            middle = (left + right) // 2
            if nums[middle] == target:
                return middle
            if nums[middle] <= target:
                left = middle + 1
            else:
                right = middle - 1
        middle = int ((left + right) / 2)
        print (middle)
        print(left)
        print(right)
        if nums[middle] < target:
            return middle + 1
        return middle
