class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tfreq(128,0);
        for(char c : t) tfreq[c]++;
        //tfreq is the hashcode
        
        int start=0,end=0,counter=t.size(),minStart=0,minLen=INT_MAX;
        // counter represents the number of chars of t to be found in s.
        int size = s.size();
        
        while(end<size){
            //if character in s exists in t => i.e., if char exists in t, the freq would be positive. (0if non-existent, -ve never happens)
            if(tfreq[s[end]]>0){
                counter--; //no.of chars to be found is 1 less now
            }
            tfreq[s[end]]--; //reduce the freq of that char regardless of its presence in t
            //if the char is not in t, it will result in negative frequency. later as we move the start pointer to the left, we will increase the freq of this char. So we will essentially cancel out all the subtractions we do on the char 
            end++; //window to the right
            
            //by this time, if we have reached the matching substring, we will start resizing. If not, then the window has been expanded on the right size and its proceeding
            //when counter=0, tfreq should have all 0s
            while(counter==0){
                if(end-start<minLen){
                    minStart=start;
                    minLen = end-start;
                } //update the head and tail and length if needed, and then continue resizing
                tfreq[s[start]]++; 
                /*if the char existed in t already, then freq would be greater than 0. Otherwise it will be 0 or less than 0as we reduced the frequency of the char earlier regardless of it being in t or not*/
                if(tfreq[s[start]]>0) counter++;
                start++;
            }
            
        }
        if(minLen!=INT_MAX){
            return s.substr(minStart,minLen);
        }
        return "";
    }
};
