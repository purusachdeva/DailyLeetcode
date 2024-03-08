class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for(auto i : nums) {
            mp[i]++;
            maxi = max(mp[i], maxi);
        }

        int count = 0;
        for(auto i : nums) {
            if(mp[i] == maxi) count++;
        }

        return count;
    }   
};