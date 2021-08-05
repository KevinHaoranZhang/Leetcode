class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        solution = collections.defaultdict(list)
        for string in strs:
            solution[tuple(sorted(string))].append(string)
        return solution.values()
