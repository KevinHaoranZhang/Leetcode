class Solution {
public:
    int myAtoi(string str) {
        int i;
        bool negative = false;
        for (i = 0; i < str.size(); i++){
            if (str[i] != ' '){
                break;
            }
        }
        if(i == str.size())
            return 0;
        if(str[i] == '-' && i+1 != str.size()){
            negative = true;
            return findnum (str.substr(i+1, str.size()), negative);
        }
        if (str[i] == '+' && i+1 != str.size())
            return findnum (str.substr(i+1, str.size()), negative);
        return findnum (str.substr(i, str.size()), negative);
        
    }
    int findnum (string str, bool negative){
        if (str.size() == 0)
            return 0;
        int num = 0;
        for(int i = 0; i < str.size(); i++){
            if( int(str[i]) < 58 && int(str[i]) > 47 ){
                if(!negative && (num > INT_MAX/10 || (num==INT_MAX/10 && (str[i]-'0')>=7))){
                    return INT_MAX;
                }
                if(negative && (num > INT_MAX/10 || (num==INT_MAX/10 && (str[i]-'0')>=8))){
                    return INT_MIN;
                }
                num = num*10 + (str[i] - '0');
            }
            else
                break;
        }
        if(negative)
            return -num;
        return num;
        
    }
};
