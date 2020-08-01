class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0 && haystack.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++){
            int j = 0;
            int z = i;
            int count = 0;
            if(haystack.size() - i < needle.size())
                return -1;
            while(haystack[z] == needle[j] && z < haystack.size() && j < needle.size()){
                count++;
                z++;
                j++;
            }
            if(count == needle.size()){
                return i;
            }
        }
        return -1;
    }
};
