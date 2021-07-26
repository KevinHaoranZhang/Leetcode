class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals
        intervals = sorted(intervals, key=lambda x: x[0])
        current_start, current_end = intervals[0][0],intervals[0][1]
        solution = []
        for i in range(1, len(intervals)):
            if intervals[i][0] <= current_end:
                if current_end < intervals[i][1]:
                    current_end = intervals[i][1]
            else:
                solution.append([current_start, current_end])
                current_start, current_end = intervals[i][0],intervals[i][1]
        solution.append([current_start, current_end])
        return solution
