class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
            return "1";
        }
        
        string res = countAndSay(n-1);
        
        string newRes = "";
        int count = 0;
        char c = '\0';
        for(int i = 0; i < res.size();)
        {
            c = res.at(i);
            count = 0;
            
            int j = i+1;
            for(; j < res.size(); ++j)
            {
                if(res.at(j) != c)
                {
                    break;
                }
            }   
            count = j - i;
            
            newRes += to_string(count);
            newRes += c;
                       
            i = j;
        }
        
        return newRes;
    }
};
