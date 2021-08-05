class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // greedy: assign the least size cookie to the child who has the smallest content
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // child: index in child array, increment when meet their content
        // cookie: index in cookie array, increment every time
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {
                ++child;
            }
            ++cookie;
        }
        return child;
    }
};
