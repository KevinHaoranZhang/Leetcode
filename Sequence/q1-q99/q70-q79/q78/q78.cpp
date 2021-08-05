class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> sub_solution;
        for (int i = 0; i <= nums.size(); i++) {
            backtrack(0, i, sub_solution, solution, nums);
        }
        return solution;
        
    }
    
    void backtrack(int start, int length, vector<int> sub_solution, vector<vector<int>> & solution, vector<int> nums) {
        if (sub_solution.size() == length) {
            solution.push_back(sub_solution);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            sub_solution.push_back(nums[i]);
            backtrack(i + 1, length, sub_solution, solution, nums);
            sub_solution.pop_back();
        }
            
    }
};
