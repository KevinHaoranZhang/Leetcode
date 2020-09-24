class Solution {
public:
    string simplifyPath(string path) {
        int i = 0, size = path.size();
        vector<string> path_name;
        string solution = "/";
        while (i < size) {
            string word = "";
            while (i < size && path[i] != '/') {
                word += path[i++];
            }
            if (word == "..") {
                if (path_name.size() > 0) {
                    path_name.pop_back();
                }
            } else if (word != "" && word != ".") {
                path_name.push_back(word);
            }
            ++i;
        }
        for (auto i : path_name) {
            solution += i + "/";
        }
        return solution == "/" ? solution : solution.substr(0,solution.length()-1);
    }
};
