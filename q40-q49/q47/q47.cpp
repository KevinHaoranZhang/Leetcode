class Solution {
public:
    void solve(vector<vector<int>> &ans,int start,vector<int> nums)
    {
        if(start==nums.size()-1)
            ans.push_back(nums);
        else
        {
            for(int i=start;i<nums.size();i++)
            {
                if(i==start || nums[i]!=nums[start])
                {
                    swap(nums[i],nums[start]);
                    solve(ans,start+1,nums);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();if(n==0)return {{}};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(ans,0,nums);
        return ans;
    }
};
