from itertools import combinations
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
      solution = []
      for i in range(len(nums) + 1):
        for j in list(combinations(nums, i)):
          solution += [j]
      return solution
