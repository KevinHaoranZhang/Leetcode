class Solution {
public:
    int candy(vector<int>& ratings) {
        int child_num = ratings.size();
        // meet condition 1: assign all children with 1 candy
        vector<int> candies(child_num, 1);
        // scan from left to right
        // if right > left in ratings, assign one more candies to the right
        for (int i = 1; i < child_num; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        // scan from right to left
        // if left > right in ratings and short in candies, assign one more candies to the left
        for (int i = child_num - 1; i > 0; --i) {
            if (ratings[i-1] > ratings[i] && candies[i-1] <= candies[i]) {
                candies[i-1] = candies[i] + 1;
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
