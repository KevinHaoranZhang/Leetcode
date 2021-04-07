class Solution:
    def grayCode(self, n: int) -> List[int]:
        result = []
        for i in range(0, pow(2, n)):
            result.append(i ^ i >> 1)
        return result;
