class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string solution;
        int size = s.size();
        int jump = 2*numRows-2;
        for (int i = 0; i < numRows; i++){
            for(int j = 0; j+i < size; j += jump){
                solution += s[j+i];
                if (i != 0 && i != numRows-1 && j+jump-i < size){
                    solution += s[j+jump-i];
                }
            }
        }
        return solution;
    }
};
