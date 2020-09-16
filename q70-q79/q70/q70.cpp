class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n, 0);
        return helper(0, n, mem);
    }
    int helper(int cur, int n, vector<int>& mem){
        if (cur > n)
            return 0;
        if (cur == n)
            return 1;
        if (mem[cur] > 0)
            return mem[cur];
        mem[cur] = helper(cur + 1, n, mem) + helper(cur + 2, n, mem);
        return mem[cur];
    }
};
