class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string solution = "";
        if (!strs.size())
            return solution;
        int shortest_str_length = INT_MAX;
        int list_size = strs.size();
        bool is_prefix = true;
        for(int i = 0; i < list_size; i++){
            if(strs[i].size() < shortest_str_length)
                shortest_str_length = strs[i].size();
        }
        for(int char_index = 0; char_index < shortest_str_length; char_index++){
            for(int str_index = 0; str_index < list_size - 1; str_index++){
                if(strs[str_index][char_index] != strs[str_index+1][char_index]){
                    is_prefix = false;
                    break;
                }
            }
            if (is_prefix){
                solution += strs[0][char_index];
            }
        }
        return solution;
    }
};
