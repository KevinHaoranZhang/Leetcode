class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s;
        size = len(s)
        jump = 2*numRows -2
        strlist = []
        for i in range(numRows):
            for j in range(i, size, jump):
                strlist.append(s[j])
                if i != numRows -1  and i != 0 and j + jump - 2*i < size:
                    strlist.append(s[j + jump - 2*i])
        solution = ''.join(strlist)
        return solution
