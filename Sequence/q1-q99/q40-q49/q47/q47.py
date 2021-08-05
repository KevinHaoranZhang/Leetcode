class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)
        ret = list()
        def backtrack(give=[],arr=nums,placed=[]):
            if len(give) == length:
                ret.append(give)
            else:
                for index in range(0,len(arr)):
                    if arr[index] in placed:
                        continue
                    placed.append(arr[index])
                    backtrack(give+[arr[index]],arr[0:index]+arr[index+1:],[])
        backtrack()
        return ret
