class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for(int i = 1, j = nums.size() - 2; i < nums.size(); i++, j--) {
            left[i] = left[i-1]*nums[i-1];
            right[j] = right[j+1]*nums[j+1];
        }

        for(int i = 0; i < ans.size(); i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};