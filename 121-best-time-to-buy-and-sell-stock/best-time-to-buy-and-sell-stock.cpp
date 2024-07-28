class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;

        int maxi = 0;
        while (i <= j && j < prices.size()) {
            maxi = max(maxi, prices[j] - prices[i]);

            if (prices[i] > prices[j]) i = j;
            
            else j++;
        }

        return maxi;
    }
};