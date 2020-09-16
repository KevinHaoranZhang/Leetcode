class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int a_index = a.size() - 1;
        int b_index = b.size() - 1;
        string solution;
        while (carry != 0 || a_index >= 0 || b_index >= 0) {
            int x,y;
            if (a_index >=0)  
                x = a[a_index]-'0';
            else 
                x = 0;
            if (b_index >= 0)  
                y = b[b_index]-'0';
            else 
                y = 0;
            int sum = (x + y + carry) % 2;
            carry = (x + y + carry) / 2;
            solution.insert(0, to_string(sum));
            a_index--;
            b_index--;
        }
        return solution;
    }
};
