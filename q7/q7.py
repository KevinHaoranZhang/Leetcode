class Solution:
    def reverse(self, x: int) -> int:
        solution = 0
        if(x > 0):
            positive = 1
        else:
            positive = 0
            x = 0 - x
        while x != 0:
            pop = x % 10
            x = int(x/10)
            solution = solution *10 + pop
        if positive and solution <= 2**31 - 1:
            return solution
        elif positive < 1 and solution < 2**31 - 1:
            return (-solution) 
        return 0
