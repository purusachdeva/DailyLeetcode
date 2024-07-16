class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto i : nums) m[i]++;

        vector<vector<int>> freq(nums.size() + 1);

        for(auto [n, c] : m) {
            freq[c].push_back(n);
        }

        vector<int> result;

        for(int i = freq.size() - 1; i >= 0; i--) {
            if(result.size() == k) break;

            for(auto j : freq[i]) {
                result.push_back(j);
            }
        }

        return result;
    }
};