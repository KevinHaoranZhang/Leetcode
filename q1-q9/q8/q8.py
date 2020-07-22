class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        if len(str) == 0:
            return 0
        negative = False
        if(str[0] == '-'):
            negative = True
            str = str[1:]
        elif(str[0] == '+'):
            nagative = False
            str = str[1:]
        solution = 0
        for i in range(len(str)):
            if str[i].isdigit():
                solution = int (solution*10 + ord(str[i]) - 48)
            else:
                break
        if negative:
            solution = -solution
        if solution > 2**31 - 1:
            solution = (2**31 - 1)
        elif solution < -1 * 2**31:
            solution = (-1 * 2**31)
        return solution
