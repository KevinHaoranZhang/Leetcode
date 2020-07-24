
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        nums.sort()
        solution = []
        
        for i in range(0, len(nums)-2):
            if (not (i > 0 and nums[i] == nums[i-1])):
                left = i + 1
                right = len(nums) -1 
                while left < right:
                    if (nums[left] + nums[right] == -nums[i]):
                        if(nums[left] == nums[right]):
                            solution.append([nums[left], nums[right], nums[i]])
                            break
                        else:
                            solution.append([nums[left], nums[right], nums[i]])
                            while left < right -1 and nums[left] == nums[left+1]:
                                left += 1
                            while left < right -1 and nums[right] == nums[right-1]:
                                right -= 1
                            left += 1
                            right -= 1
                    elif nums[left] + nums[right] > -nums[i]:
                        right -= 1
                    else:
                        left += 1
                
        return solution

