#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int, int> hash_table;
        std::vector<int> solution;
        for (int i = 0; i < nums.size(); i++){
            int target_remain = target - nums[i];
            if(hash_table.find(target_remain) != hash_table.end()){
                
                solution.push_back(hash_table.find(target_remain)->second);
                solution.push_back(i);
                return solution;
            }
            hash_table.insert(std::make_pair(nums[i], i));
        }
        return solution;
    }
};
