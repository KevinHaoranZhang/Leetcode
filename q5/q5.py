class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandCenter(s, left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right-left-1
    
        if (len(s) == 0):
            return ""
        end = 0
        start = 0
        for i in range(len(s)):
            len1 = expandCenter(s, i, i)
            len2 = expandCenter(s,i, i+1)
            length = max(len1,len2)
            if length > (end - start+1):
                if length % 2 == 1:
                    start = i - (length - 1)//2
                    end = i + (length - 1)//2
                else:
                    start = i - (length - 2)//2
                    end = i + length//2
        return s[start:end+1]

        
    
