class Solution(object):
    def subsetsWithDup(self, nums):
        ans = []
        nums.sort()
        self.subsetsWithDup_helper(nums, 0, [], ans)
        return ans
        
    def subsetsWithDup_helper(self, nums, start, sub_ans, ans):
        ans.append(copy.deepcopy(sub_ans))
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue
            sub_ans.append(nums[i])
            self.subsetsWithDup_helper(nums, i + 1, sub_ans, ans)
            sub_ans.pop()
