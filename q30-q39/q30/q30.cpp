#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length();
        vector<int> ans;
        int sz=words.size();
        if(n==0 or sz==0)return ans;
        int len=words[0].length();
        
        unordered_map<string,int> cnt;
        for(auto it:words)cnt[it]++;
        for(int i=0;i<n-len*sz+1;i++){
            int j=0;
            unordered_map<string,int> seen;
            for(;j<sz;j++){
                string temp=s.substr(i+j*len,len);
                if(!cnt.count(temp))break;
                seen[temp]++;
                if(seen[temp]>cnt[temp])break;
            }
            if(j==sz)ans.push_back(i);
        }
        return ans;
    }
};
