#include <vector>
class Solution {
public:
    vector<string> solution;
    vector<string> generateParenthesis(int n) {
        string s = "";
        int left = 0, right = 0;
        backtrack(s, left, right, n);
        return this->solution;
    }
    void backtrack(string s, int left, int right, int n){
        if(s.size() == 2 * n){
            this->solution.push_back(s);
            return;
        }
        if (left < n){
            backtrack(s+"(", left+1, right, n);
        }
        if (right < left){
            backtrack(s+")", left, right+1, n);
        }
        
    }
};
