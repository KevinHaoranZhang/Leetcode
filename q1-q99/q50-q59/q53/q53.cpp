class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_max = nums[0];
        int solution = nums[0];
        for (int i = 1; i < nums.size(); i++){
            current_max = nums[i] > current_max + nums[i] ? nums[i] : current_max + nums[i];
            if (current_max > solution)
                solution = current_max;
        }
        return solution;
    }
};
