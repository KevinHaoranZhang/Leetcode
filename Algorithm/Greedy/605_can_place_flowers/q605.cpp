class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flower_planted = 0, total_spot = flowerbed.size();
        for (int i = 0; i < total_spot; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == total_spot - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                ++flower_planted;
            }
            if (flower_planted >= n) {
                return true;
            }
        }
        return false;
    }
};
