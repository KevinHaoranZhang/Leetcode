#include <vector>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<string> solution;
        if(!digits.size())
            return solution;
        std::vector<string> phone{ " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        queue<string> q;
        q.push("");
                                  
        for (char digit : digits){
            int index = digit - '0';
            int i = q.size();
            while(i--){
                string top = q.front();
                q.pop();
                for(char phone_char : phone[index]){
                    q.push(top + phone_char);
                }
            }
        }
        while(!q.empty()){
            string top = q.front();
            q.pop();
            solution.push_back(top);
        }
        return solution;
    }

};
