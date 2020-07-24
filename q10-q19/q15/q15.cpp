class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        
        if(nums.size() < 3)
            return v;
        bool flag=true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                flag=false;
                break;
            }
        }
        if(flag){
            v.push_back({0, 0, 0});
            return v;
        }
        
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
               int l=i+1, r=nums.size()-1;
                while(l<r){
                    if(nums[i]+nums[l]+nums[r] == 0){
                        if(s.find({nums[i], nums[l], nums[r]}) == s.end()){
                        v.push_back({nums[i], nums[l], nums[r]});
                        s.insert({nums[i], nums[l], nums[r]});
                        }
                        l++;
                    }
                    else if(nums[i]+nums[l]< -nums[r])
                        l++;
                    else
                        r--;
                }
            }
        return v;
    }
};
