#include <algorithm>
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> path;
        std::vector<std::vector<int>> solution;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, solution);
        return solution;
    }
private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& solution){
        if (target == 0){
            solution.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++){
            if (candidates[i] > target)
                return;
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, path, solution);
            path.pop_back();
        }
    }
};
