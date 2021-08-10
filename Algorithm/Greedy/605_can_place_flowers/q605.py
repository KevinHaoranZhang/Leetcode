class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        total_spot, flower_planted = len(flowerbed), 0
        for i in range(0, total_spot):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == total_spot - 1 or flowerbed[i + 1] == 0):
                flower_planted += 1
                flowerbed[i] = 1
            if flower_planted >= n:
                return True
        return False
