class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> solution (n, vector<int>(n));
        int count = 1;
        int layer;
        for (layer = 0; layer < (n + 1)/2; layer++){
            for (int ptr1 = layer; ptr1 < n - layer - 1; ptr1++){
                solution[layer][ptr1] = count++;
            }
            for (int ptr2 = layer; ptr2 < n - layer - 1; ptr2++){
                solution[ptr2][n - layer - 1] = count++;
            }
            for (int ptr3 = n - layer - 1; ptr3 > layer; ptr3--){
                solution[n - layer - 1][ptr3] = count++;
            }
            for (int ptr4 = n - layer - 1; ptr4 > layer; ptr4--){
                solution[ptr4][layer] = count++;
            }
        }
        if (n % 2)
            solution[n/2][n/2] = count;
        return solution;
    }
};
