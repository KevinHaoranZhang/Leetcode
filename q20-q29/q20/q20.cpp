#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack_check;
        if (s.size() == 1)
            return false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack_check.push(s[i]);
            }else if (s[i] == ']' && !stack_check.empty()){
                if(stack_check.top() != '[')
                    return false;
                else 
                    stack_check.pop();
            }else if (s[i] == '}' && !stack_check.empty()){
                if(stack_check.top() != '{')
                    return false;
                else 
                    stack_check.pop();
            }else if (s[i] == ')' && !stack_check.empty()){
               
                if(stack_check.top() != '(')
                    return false;
                else 
                    stack_check.pop();
            }else{
                stack_check.push(s[i]);
            }
                
        }
        if(!stack_check.empty()){
            return false;
        }
            
        return true;
    }
};
