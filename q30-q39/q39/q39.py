class Solution:
    def dfs(self, path, solution, target, index, candidates):
        if target == 0:
            solution.append(path[:])
            return
        for i in range(index, len(candidates)):
            if candidates[i] > target:
                return
            path.append(candidates[i])
            self.dfs(path, solution, target-candidates[i], i,candidates)
            path.pop()
            
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        solution = []
        candidates.sort()
        self.dfs(path, solution, target, 0, candidates)
        return solution
