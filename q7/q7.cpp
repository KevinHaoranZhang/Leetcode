class Solution {
public:
    int reverse(int x) {
        int solution = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if (solution > INT_MAX/10 || (solution == INT_MAX / 10 && pop > 7)) return 0;
            if (solution < INT_MIN/10 || (solution == INT_MIN / 10 && pop < -8)) return 0;
            solution = solution * 10 + pop;
        }
        return solution;
    }
};
