class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left, middle, right = 0, 0, len(nums) - 1
        while middle <= right:
            if nums[middle] == 0:
                temp = nums[middle]
                nums[middle] = nums[left]
                nums[left] = temp
                middle += 1
                left += 1
            elif nums[middle] == 1:
                middle += 1
            else:
                temp = nums[middle]
                nums[middle] = nums[right]
                nums[right] = temp
                right -= 1
                
                
