class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        helper(solution, nums, 0);
        return solution;
    }
    void helper(vector<vector<int>>& solution, vector<int>& nums, int current_index){
        if (current_index == nums.size()){
            solution.push_back(nums);
            return;
        }
        for (int i = current_index; i < nums.size(); i++){
            int temp = nums[i];
            nums[i] = nums[current_index];
            nums[current_index] = temp;
            helper(solution, nums, current_index + 1);
            temp = nums[i];
            nums[i] = nums[current_index];
            nums[current_index] = temp;
        }
    }
};
