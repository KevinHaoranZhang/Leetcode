class Solution {
public:
    int maxArea(vector<int>& height) {
        int solution = 0, current_area = 0;
        int left = 0, right = height.size()-1;
        while(left != right){
            current_area = height[left] < height[right] ? height[left]*(right-left) : height[right]*(right-left);
            solution = current_area > solution ? current_area : solution;
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return solution;
    }
};
