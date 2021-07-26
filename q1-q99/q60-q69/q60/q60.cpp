class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact_arr (n, 1);
        for (int i = 1; i < n; i++){
            fact_arr[i] = fact_arr[i-1] * i;
        }
        --k;
        string solution;
        for (int i = 1; i <= n; i++)
            solution.push_back(i + '0');
        for (int i = 1, j = n - 1; j > 0; i++){
            if (k < fact_arr[j]){
                --j;
                i = n - 1 - j;
                continue;
            }
            swap(solution[n - 1 - j], solution[i]);
            k -= fact_arr[j];
        }
        return solution;
    }
};
