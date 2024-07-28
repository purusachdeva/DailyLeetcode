class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;

        int maxi = 0;
        while (i <= j && j < prices.size()) {
            if (prices[j] > prices[i]) maxi = max(maxi, prices[j] - prices[i]);
            else i = j;

            j++;
        }

        return maxi;
    }
};