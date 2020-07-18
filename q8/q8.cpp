class Solution {
public:
    bool isPalindrome(int x) {
         if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int partial_revert = 0;
        while(x > partial_revert){
            partial_revert = partial_revert * 10 + x % 10;
            x /= 10;
        }
        return x == partial_revert || x == partial_revert / 10;
    }
};
