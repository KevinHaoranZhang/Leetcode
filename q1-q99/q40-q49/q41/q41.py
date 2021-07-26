class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        index = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                index += 1
            elif nums[i] <= 0:
                nums[i] = 1
        if index == 0:
            return 1
        
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            if index < len(nums) and nums[index] > 0:
                nums[index] = - nums[index]
        for i in range(len(nums)):
            if nums[i] > 0:
                return i + 1
        return len(nums) + 1
            
                
