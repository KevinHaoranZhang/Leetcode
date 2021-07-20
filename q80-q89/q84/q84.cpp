class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index_stack;
        
        // store maximum extentable index from left side
        int left_index[heights.size()];
        // store maximum extentable index from right side
        int right_index[heights.size()];
        
        // loop from left, find corresponding left index
        for (int i = 0; i < heights.size(); ++i) {
            while (!index_stack.empty() && heights[i] <= heights[index_stack.top()]) {
                index_stack.pop();
            }
            left_index[i] = index_stack.empty() ? 0 : index_stack.top() + 1;
            index_stack.push(i);
        }
        while(!index_stack.empty()) {
            index_stack.pop();
        }
        // loop from right, find corresponding right index
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!index_stack.empty() && heights[i] <= heights[index_stack.top()]) {
                index_stack.pop();
            }
            right_index[i] = index_stack.empty() ? heights.size() - 1 : index_stack.top() - 1;
            index_stack.push(i);
        }
        // find max area = (current height * (right - left + 1))
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            max_area = max(max_area, heights[i] * (right_index[i] - left_index[i] + 1));
        }
        return max_area;
        
    }
};
