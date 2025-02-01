class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxP = 1, minP = 1;

        int totalMax = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                maxP = 1;
                minP = 1;
                continue;
            }

            int prod1 = nums[i] * maxP;
            int prod2 = nums[i] * minP;

            maxP = max(max(prod1, prod2), nums[i]);
            minP = min(min(prod1, prod2), nums[i]);


            totalMax = max(maxP, totalMax);
        }

        return totalMax;
    }
};