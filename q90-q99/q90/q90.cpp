class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        subsetsWithDup_helper(nums, 0, vector<int>(), ans);
        return ans;
    }

    void subsetsWithDup_helper(vector<int>& nums, int start, vector<int> sub_ans, vector<vector<int>>& ans) {
        ans.push_back(sub_ans);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            sub_ans.push_back(nums[i]);
            subsetsWithDup_helper(nums, i + 1, sub_ans, ans);
            sub_ans.pop_back();
        }
    }
};
