class Solution:
    def intToRoman(self, num: int) -> str:
        solution = ""
        pq = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        letters = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        while num != 0:
            for i in range(len(pq)):
                if(pq[i] <= num):
                    num -= pq[i]
                    solution += letters[i]
                    break
        return solution
