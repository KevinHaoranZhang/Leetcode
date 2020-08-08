class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        int middle = 0;
        while (left < right){
            middle = (left + right) / 2;
            if (nums[middle] == target){
                return middle;
            }
            if (nums[middle] <= target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        middle = (left + right) / 2;
        if (target > nums[middle])
            return middle + 1;
        else 
            return middle;
    }
};
