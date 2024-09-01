class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n, 0));

        int j = 0;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                ans[i][k] = original[j];
                j++;
            }
        }

        return ans;
    }
};