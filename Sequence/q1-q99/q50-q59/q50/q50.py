class Solution:
    def myPow(self, x: float, n: int) -> float:
        m = n
        solution = 1.0
        if n < 0:
            m = -n
        while m > 0:
            if m % 2:
                solution = solution * x
                m = m - 1
            else:
                x = x * x
                m = m / 2
        if n < 0:
            return 1.0/solution
        return solution
                
            
