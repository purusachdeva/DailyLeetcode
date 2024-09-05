class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (auto i : rolls) sum += i;

        int nSum = mean * (n + rolls.size()) - sum;

        vector<int> ans(n, 1);
        nSum -= n;
        
        // Create a vector with size = n and sum = nSum
        int i = 0;
        while (nSum != 0) {
            if (i == n) return {};
            if (ans[i] < 6) {
                ans[i]++;
                nSum--;
            } else i++;
        }

        return ans;
    }
};