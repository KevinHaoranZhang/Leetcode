class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        unordered_map<string, vector<string>> hash_table;
        for(int i = 0; i < strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            hash_table[word].push_back(strs[i]);   
        }
        for(auto it : hash_table){
            solution.push_back(it.second);
        }
        return solution;
    }
};
