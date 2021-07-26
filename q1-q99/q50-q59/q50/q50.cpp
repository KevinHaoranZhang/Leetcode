class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if (n < 0){
            m = - 1 * m;
        }
        double solution = 1.0;
        while (m > 0){
            if (m % 2){
                m = m - 1;
                solution = solution * x;
            } else {
                x = x * x;
                m = m / 2;
            }
        }
        if (n < 0){
            return 1.0/solution;
        }
        return solution;
    }
};
