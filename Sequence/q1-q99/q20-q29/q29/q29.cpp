class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor < 0 && dividend != divisor){
            return abs((dividend + 1) / divisor);
        }
        else if(dividend == INT_MIN && divisor > 0){
            return (dividend ) / divisor;
        }
        else if(dividend == INT_MIN && divisor < 0){
            return abs((dividend) / divisor);
        }
        return dividend/divisor;
    }
};
