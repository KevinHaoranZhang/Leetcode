class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // change elements that are less than 1 to 1//
        // at the same time, check if 1 is in the array//
        // if not, return 1;
                
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            
            if (nums[i] <= 0)
                nums[i] = 1;
        }
        
        // if 1 is not in the array, return 1//
        
        if (count == 0)
            return 1;
        
        // use nums[nums[i]] to change element from positive to negative//
        // negative number is a mark that this element(index) was visited//
        // also need to make sure index is within size//
        
        int index;
        
        for (int i = 0; i < nums.size(); i++) {
            index = abs(nums[i])-1;
            
            if(index <= nums.size()-1 && nums[index] > 0)
                nums[index] = -nums[index];
        }
        
        // find the first element that is positive//
        // return that index plus one//
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) {
                ans = i;
                break;
            }
        }
        // if all elements are negative//
        // return size+1, because all the smallest numbers are in the array//
        
        if (ans == 0)
            return nums.size()+1;
        
        return ans+1;
    }
};
