class Solution:
    def minWindow(self, s: str, t: str) -> str:
        hash_map = [0 for _ in range(129)]
        for char in t:
            hash_map[ord(char)] += 1
        end, start, min_len, min_start, size, count = 0, 0, sys.maxsize, 0, len(s), len(t)
        while end < size:
            if hash_map[ord(s[end])] > 0:
                count -= 1
            hash_map[ord(s[end])] -= 1
            end += 1
            while count ==0:
                if end-start < min_len:
                    min_start = start;
                    min_len = end-start
                hash_map[ord(s[start])] += 1
                if hash_map[ord(s[start])]>0:
                    count += 1
                start += 1
        if min_len < sys.maxsize:
            return s[min_start:min_start + min_len]
        return ""

                            
        
