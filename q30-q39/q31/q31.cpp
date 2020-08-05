#include <iostream>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i+1] <= nums[i]){
            --i;
        }
        if (i >= 0){
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]){
                --j;
            }
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
        int j = nums.size() - 1;
        i ++;
        while( i < j ){
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j--;
        }
    }
};
