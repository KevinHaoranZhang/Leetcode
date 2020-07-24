#include <algorithm>
#include <cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int solution = 0;
        int current_diff = 0;
        int smallest_diff = INT_MAX;
        int current_sum = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                current_sum = nums[i] + nums[right] + nums[left];
                if(abs(target - current_sum) < smallest_diff){
                    smallest_diff = abs(target - current_sum);
                    solution = current_sum;
                }
                if (current_sum < target)
                    left++;
                else if (current_sum > target)
                    right--;
                else
                    return target;
            }   
        }
        return solution;
    }
};
