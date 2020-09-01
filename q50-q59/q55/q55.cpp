class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_position = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--){
            if (i + nums[i] >= last_position)
                last_position = i;
        }
        return last_position == 0;
    }
};
