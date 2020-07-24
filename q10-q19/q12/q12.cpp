// #include <iostream>
#include <vector>
class Solution {
public:
    string intToRoman(int num) {
        string solution;
        if (num < 0){
            num = -num;
        }
        std::vector<int> priority_queue{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<string> letters{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        // std::cout << letters.size() << std::endl;
        while(num != 0){
            for(int i = 0; i < priority_queue.size(); i++){
                // std::cout << "num: " << num << std::endl;
                if(priority_queue[i] <= num){
                    solution += letters[i];
                    num -= priority_queue[i];
                    break;
                }
            }
        }
        return solution;
    }
};
