class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x, solution = 0;
        while (left <= right){
            int middle = left + (right - left) / 2;
            if (middle <= x / middle){
                solution = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }
        return solution;
    }
};
