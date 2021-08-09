class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        // sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        // greedy: always keep smallest end time intervals
        int total_operation = 0, prev_end = intervals[0][1], size = intervals.size();
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] < prev_end) {
                ++total_operation;
            } else {
                prev_end = intervals[i][1];
            }
        }
        return total_operation;
    }
};
