class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (auto i : rolls) sum += i;

        int nSum = mean * (n + rolls.size()) - sum;

        // Edge case
        if (n*6 < nSum || nSum < n) return {};

        // Create a vector with size = n and sum = nSum
        int rem = nSum % n;
        int q = nSum / n;

        vector<int> ans(n, q);

        for (int i = 1; i <= rem; i++) {
            ans[i]++;
        }

        return ans;
    }
};