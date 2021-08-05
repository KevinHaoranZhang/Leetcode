class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if(a.size() <= 2) {
            return a.size();
        }
        for (int i=0;i != a.size()-2; i++) {
            if (a[i] == a[i+1] && a[i] == a[i+2]) {
                a.erase(a.begin()+i);
                i--;
            }       
        }
        return a.size();
    }
}; 
