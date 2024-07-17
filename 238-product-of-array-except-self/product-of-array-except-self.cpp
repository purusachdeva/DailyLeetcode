class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        
        int product = 1;
        for(int j = nums.size() - 1; j >= 0; j--) {
            ans[j] = ans[j]*product;
            product *= nums[j];
        }

        return ans;
    }
};