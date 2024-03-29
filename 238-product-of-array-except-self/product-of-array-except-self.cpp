class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        answer[0] = 1;
        for(int i = 1; i < nums.size(); i++) 
            answer[i] = answer[i-1] * nums[i-1];

        int right = 1;
        for(int i = nums.size()-2; i >= 0; i--) {
            right = right*nums[i+1];
            answer[i] *= right;
        }

        return answer;
    }
};