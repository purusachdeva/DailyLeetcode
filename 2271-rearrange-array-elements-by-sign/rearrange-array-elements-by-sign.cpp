class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> positive;
        vector<int> negative;
        for(auto i : nums) {
            if(i > 0) positive.push_back(i);
            else negative.push_back(i);
        }

        int a = 0, b = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0) nums[i] = positive[a++];
            else nums[i] = negative[b++];
        }

        return nums;
    }
};