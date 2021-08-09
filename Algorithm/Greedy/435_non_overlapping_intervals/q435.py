class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()        
        prev_end = intervals[0][1]
        total_operation = 0
        for i in range(1, len(intervals)):
            if prev_end > intervals[i][0]:
                total_operation += 1
                prev_end = intervals[i][1] if intervals[i][1] < prev_end else prev_end
            else:
                prev_end = intervals[i][1]
        return total_operation
