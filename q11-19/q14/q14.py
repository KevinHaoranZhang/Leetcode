class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        solution = ""
        if len(strs) == 0:
            return solution;
        list_size = len(strs)
        shortest_str = inf
        is_prefix = True
        for i in range(list_size):
            if(len(strs[i]) < shortest_str):
                shortest_str = len(strs[i])
                
        for char_index in range(shortest_str):
            for str_index in range(list_size-1):
                if strs[str_index][char_index] != strs[str_index+1][char_index]:
                    is_prefix = False
                    break
            if is_prefix:
                solution += strs[0][char_index]
        return solution
