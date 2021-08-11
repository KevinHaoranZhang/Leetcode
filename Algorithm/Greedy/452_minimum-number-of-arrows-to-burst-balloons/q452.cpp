class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        // sort by end points
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b)->bool{
        if(a[1] == b[1]){
            return a[0] < b[0];
        }

        return a[1] < b[1];
        });
        int arrow = 1, prev_end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            // within range, only one arrow needed
            if (points[i][0] <= prev_end) {
                continue;
            }
            ++arrow;
            prev_end = points[i][1];
        }
        return arrow;
    }
};
