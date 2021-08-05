class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substring = []
        solution = 0
        for i in range(len(s)):
            if s[i] in substring:
                if solution < len(substring):
                    solution = len(substring)
                del substring[0:substring.index(s[i])+1]
            substring.append(s[i])
        if solution < len(substring):
            solution = len(substring)
        return solution
