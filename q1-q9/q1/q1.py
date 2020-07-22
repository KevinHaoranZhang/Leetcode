class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        solution = [];
        hashtable = {}
        for index, num in enumerate(nums):
            target_remain = target-num
            if target_remain in hashtable:
                return [hashtable[target_remain], index]
            hashtable[num] = index
        return []
