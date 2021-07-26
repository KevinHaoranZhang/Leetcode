
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0){
            return "";
        }
        if (s.size() == 1){
            return s;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++){
            int len1 = expandCenter(s, i, i);
            int len2 = expandCenter(s, i, i+1);
            int len = len1 > len2 ? len1 : len2;
            if (len > end -start){
                start = i - (len - 1)/2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
    
    int expandCenter(string str, int left, int right){
        while(left >= 0 && right < str.size() && str[left] == str[right]){
            left --;
            right ++;
        }
        return right-left-1;
    }
};
