class Solution:
    def jump(self, nums: List[int]) -> int:
        i = 0
        result = 0
        cur = 0
        size = len(nums)
        while cur < size - 1:
            result += 1
            pre = cur
            for i in range(i, pre + 1):
                cur = max(cur, nums[i] + i)
        return result;
