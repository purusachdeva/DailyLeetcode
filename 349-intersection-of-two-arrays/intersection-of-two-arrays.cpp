class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        vector<int> ans;

        for(auto i : nums1) mp[i] = true;

        for(auto i : nums2) {
            if(mp[i]) {
                ans.push_back(i);
                mp[i] = false;
            }
        }

        return ans;
    }

};