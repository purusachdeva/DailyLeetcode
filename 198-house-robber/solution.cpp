class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];

        if (nums.size() == 2)
            return max(nums[0], nums[1]);


        int n = nums.size();

        vector<int> dp(n + 1);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return dp[n];
    }
};