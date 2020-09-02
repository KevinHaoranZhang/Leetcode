class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.split()
        print(s)
        if ''.join(s) == '':
            return 0
        else:
            return len(s[-1])
