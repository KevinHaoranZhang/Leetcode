class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 0:
            return 0
        points.sort(key = lambda x:x[1])
        prev_end, arrow = points[0][1], 1
        for i in range(1, len(points)):
            if points[i][0] <= prev_end:
                continue
            arrow += 1
            prev_end = points[i][1]
        return arrow
