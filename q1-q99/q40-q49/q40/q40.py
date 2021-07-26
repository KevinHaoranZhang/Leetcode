class Solution:
    def dfs(self, path, solution, target, index, candidates):
        if target == 0:
            solution.append(path[:])
            return
        for i in range(index, len(candidates)):
            if candidates[i] > target:
                return
            if i == index or candidates[i - 1] != candidates[i]:
                path.append(candidates[i])
                self.dfs(path, solution, target-candidates[i], i + 1,candidates)
                path.pop()
            
            
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        solution = []
        candidates.sort()
        self.dfs(path, solution, target, 0, candidates)
        return solution
