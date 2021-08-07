class Solution:
    def candy(self, ratings: List[int]) -> int:
        child_num = len(ratings)
        candies = [ 1 for i in range(child_num)]
        for i in range(1, child_num):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        for i in range(child_num - 1, 0, -1):
            if ratings[i-1] > ratings[i] and candies[i-1] <= candies[i]:
                candies[i-1] = candies[i] + 1
        return sum(candies)
