class Solution {
public:
    int lengthOfLastWord(string s) {
        int solution = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] != ' ')
                solution ++;
            else if (solution != 0 && s[i] == ' ')
                return solution;
        }
        return solution;
    }
};
