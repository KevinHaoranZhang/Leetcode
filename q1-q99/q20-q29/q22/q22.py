class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        solution = []
        def backtrack(s = "", left = 0, right = 0):
            if len(s) == 2 * n:
                solution.append(s)
                return
            if left < n:
                backtrack(s+'(', left+1, right)
            if right < left:
                backtrack(s+')', left, right+1)
        
        backtrack()
        return solution
