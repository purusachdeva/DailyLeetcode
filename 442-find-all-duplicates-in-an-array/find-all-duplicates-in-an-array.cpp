class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) {
                ans.push_back(index);
            }

            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for(int i = 0; i < ans.size(); i++) 
            ans[i] = ans[i]+1;

        return ans;
    }
};