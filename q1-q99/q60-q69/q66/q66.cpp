class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last_index = digits.size() - 1;
        bool carry = true;
        while (carry){
            if (digits[last_index] == 9){
                carry = true;
                digits[last_index] = 0;
                if (last_index - 1 < 0){
                    digits.insert(digits.begin(), 1);
                    carry = false;
                } else{
                    last_index--;
                }
            } else {
                carry = false;
                digits[last_index] += 1;
            }
        }
        return digits;
    }
};
