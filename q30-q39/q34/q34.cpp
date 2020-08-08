class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int middle = 0;
        bool found = false;
        while (left <= right){
            middle = (left + right) / 2;
            if (nums[middle] == target){
                found = true;
                break;
            }
                
            if (nums[middle] <= target){
                left = middle + 1;
            } else {
                right = middle -1;
            }  
        }
        if (found){
            left = middle;
            right = middle;
            while (left - 1 >= 0 && nums[left-1] == target){
                --left;
            }
            while (right + 1 <= nums.size()-1 && nums[right+1] == target){
                ++right;
            }
            std::vector<int> solution;
            solution.push_back(left);
            solution.push_back(right);
            return solution;
        } 
        std::vector<int> solution;
        solution.push_back(-1);
        solution.push_back(-1);
        return solution;
    }
};
