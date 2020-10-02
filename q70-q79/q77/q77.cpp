class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> solution;
        helper(n, k, 1, n, path, solution);
        return solution;
    }
    
    void helper(int n, int k, int start, int & limit, vector<int> path, vector<vector<int>> & solution) {
        if (k == 0) {
            solution.push_back(path);
            return;
        }
        if (n == 0) {
            return;
        }
        for (int i = start; i <= limit - k + 1; i++) {
            path.push_back(i);
            helper(n-1, k-1, i+1, limit, path, solution);
            path.pop_back();
        }
    }
};
