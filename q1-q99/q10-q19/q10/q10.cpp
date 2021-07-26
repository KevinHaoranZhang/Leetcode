#include <vector>
class Solution {
public:
    bool isMatch(string s, string p) {
        std::vector<std::vector<bool>> dp_table (s.size()+1, vector<bool>(p.size()+1));
        dp_table[0][0] = true;
        
        for(int j = 1; j < p.size()+1; j++){
            if(p[j-1] == '*'){
                dp_table[0][j] = dp_table[0][j-2]; 
            }
        }
        for(int i = 1; i < s.size()+1; i++){
            for(int j = 1; j < p.size()+1; j++){
                if(p[j-1] == '.' || s[i-1] == p[j-1])
                    dp_table[i][j] = dp_table[i-1][j-1]; 
                else if(p[j-1] == '*'){
                    dp_table[i][j] = dp_table[i][j-2];
                    if(p[j-2] == '.' || s[i-1] == p[j-2])
                    dp_table[i][j] = dp_table[i][j] | dp_table[i-1][j]; 
                }else
                    dp_table[i][j] = false;
            }
        }
        return dp_table[s.size()][p.size()];
    }
};
