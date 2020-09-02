class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto prev = newInterval;
        vector<vector<int>> res;
        for (auto cur : intervals) {
            if (cur[1] < prev[0]) {
                res.push_back(cur);
            } else if (cur[0] <= prev[1]) {
                prev[0] = min(prev[0], cur[0]);
                prev[1] = max(prev[1], cur[1]);
            } else if (cur[0] > prev[1]) {
                res.push_back(prev);
                prev = cur;
            }
        }
        res.push_back(prev);
        return res;
    }
};
