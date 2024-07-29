class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(auto i : nums) freq[i + 100]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a + 100] == freq[b + 100]) return a > b;
            
            return freq[a + 100] < freq[b + 100];
        });

        return nums;
    }
};