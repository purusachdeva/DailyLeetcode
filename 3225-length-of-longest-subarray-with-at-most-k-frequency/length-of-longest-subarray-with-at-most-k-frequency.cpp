class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i = 0, j = 0, length = 0;

        while(j < nums.size()) {
            freq[nums[j]]++;

            if(freq[nums[j]] > k) {
                while(nums[i] != nums[j]) {
                    freq[nums[i]]--;
                    i++;
                }
                freq[nums[i]]--;
                i++;
            }

            length = max(length, j - i + 1);
            j++;
        }

        return length;
    }
};