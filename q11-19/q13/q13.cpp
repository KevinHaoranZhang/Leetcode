class Solution {
public:
    int romanToInt(string s) {
        int solution = 0;
        int i = 0;
        int n = s.size();
        while (i < n){
            if (s[i] == 'I'){
                if(i+1 < n){
                    if(s[i+1] == 'V'){
                        solution += 4;
                        i += 2;
                    }else if (s[i+1] == 'X'){
                        solution += 9;
                        i += 2;
                    }else{
                        solution += 1;
                        i += 1;
                    }
                    
                }else{
                    solution += 1;
                    i += 1;
                }
            }else if (s[i] == 'V'){
                solution += 5;
                i += 1;
            }else if (s[i] == 'X'){
                if(i+1 < n){
                    if(s[i+1] == 'L'){
                        solution += 40;
                        i += 2;
                    }else if (s[i+1] == 'C'){
                        solution += 90;
                        i += 2;
                    }else{
                        solution += 10;
                        i += 1;
                    }
                    
                }else{
                    solution += 10;
                    i += 1;
                }
            }else if (s[i] == 'L'){
                solution += 50;
                i += 1;
            }else if (s[i] == 'C'){
                if(i+1 < n){
                    if(s[i+1] == 'D'){
                        solution += 400;
                        i += 2;
                    }else if (s[i+1] == 'M'){
                        solution += 900;
                        i += 2;
                    }else{
                        solution += 100;
                        i += 1;
                    }
                    
                }else{
                    solution += 100;
                    i += 1;
                }
            }else if (s[i] == 'D'){
                solution += 500;
                i += 1;
            }else if (s[i] == 'M'){
                solution += 1000;
                i += 1;
            }
            
        }
        return solution;
    }
};
