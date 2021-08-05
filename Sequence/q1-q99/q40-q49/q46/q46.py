class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.helper(nums, [], ans)
        return ans

    def helper(self, nums, temp, ans):
        if len(nums)==0:
            ans.append(temp)
            return

        for i in range(len(nums)):
            self.helper(nums[:i]+nums[i+1:],temp+[nums[i]],ans )
    
            
