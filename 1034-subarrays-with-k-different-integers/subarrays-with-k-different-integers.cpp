class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int result = 0;

        int l_far = 0, l_near = 0;

        for(int r = 0; r < nums.size(); r++) {
            count[nums[r]]++;


            while(count.size() > k) {
                count[nums[l_near]]--;
                if(count[nums[l_near]] == 0) {
                    count.erase(nums[l_near]);
                }

                l_near++;
                l_far = l_near;
            }

            while(count[nums[l_near]] > 1) {
                count[nums[l_near]]--;
                l_near++;
            }

            if(count.size() == k) {
                result += (l_near - l_far + 1);
            }
        }

        return result;
    }
};