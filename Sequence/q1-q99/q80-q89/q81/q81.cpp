class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle = 0;
        while (left <= right) {
            middle = (right + left) / 2;
            if (nums[middle] == target || nums[left] == target || nums[right] == target) {
                return true;
            }
            if (nums[middle] < nums[right]) {
                if (nums[middle] < target && target < nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else if (nums[middle] > nums[left]) {
                if (nums[middle] > target && nums[left] < target) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                right--;
            }
        }
        return false;
            
    }
};
