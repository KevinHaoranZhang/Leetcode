class Solution {
public:
    static bool sort_helper(const vector<int> vector1, const vector<int> vector2){
        return vector1[0] < vector2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> solution;
        sort(intervals.begin(), intervals.end(), sort_helper);
        int current_start = intervals[0][0], current_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= current_end){
                current_end = intervals[i][1] > current_end ? intervals[i][1] : current_end;
            } else {
                vector<int> current_interval{current_start, current_end};
                solution.push_back(current_interval);
                current_start = intervals[i][0];
                current_end = intervals[i][1];
            }
        }
        vector<int> current_interval{current_start, current_end};
        solution.push_back(current_interval);       
        return solution;
        
    }
};
