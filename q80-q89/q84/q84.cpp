class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> ltr(n,-1);
        vector<int> rtl(n,n);
        int ans = 0;
        for (int i=0;i<heights.size();i++) {
            while (!s.empty() && heights[s.top()]>=heights[i]) 
                s.pop();
            if (!s.empty()) 
                ltr[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) 
            s.pop();
        for (int i=n-1;i>=0;i--) {
            while (!s.empty() && heights[s.top()]>=heights[i]) 
                s.pop();
            if (!s.empty()) 
                rtl[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++) 
            ans = max(ans,heights[i]*(rtl[i]-ltr[i]-1));
        
        return ans;
    }
};
